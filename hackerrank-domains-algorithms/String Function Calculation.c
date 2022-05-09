#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAXN 100000+2
char str[MAXN];
int sa[MAXN];
int rank[MAXN];
int cnt[MAXN];
int wb[MAXN];
int wv[MAXN];
int height[MAXN];
int stack[MAXN];
inline int max(int a, int b) {
    return a > b? a : b;  
}
int cmp(int *r, int a, int b, int k) {
    return r[a] == r[b] && r[a+k] == r[b+k];
}
void gen_sa(char *str, int n, int *sa, int *rank) {
    int m = 128, p;
    int i, j, k;
    int *x, *y, *t;
    x = rank; y = wb;
    memset(cnt, 0, sizeof(int) * m);
    for (i = 0; i < n; ++ i) ++ cnt[x[i] = str[i]];
    for (i = 1; i < m; ++ i) cnt[i] += cnt[i-1];
    for (i = n-1; i >= 0; -- i) sa[--cnt[x[i]]] = i;
    
    for (k = 1; k <= n; k = k << 1) {
       for (p = 0, i = n-k; i < n; ++ i) y[p++] = i;
       for (i = 0; i < n; ++ i) if (sa[i] >= k) y[p++] = sa[i] - k;
           
       memset(cnt, 0, sizeof(int) * m);
       for (i = 0; i < n; ++ i) {
           wv[i] = x[y[i]];
           ++ cnt[wv[i]];
       }
       for (i = 1; i < m; ++ i) cnt[i] += cnt[i-1];
       for (i = n-1; i >= 0; -- i) sa[--cnt[wv[i]]] = y[i];
        
       t = x; x = y; y = t; 
       x[sa[0]] = 0;
       for (p = 1, i = 0; i < n; ++ i) {
          x[sa[i]] = cmp(y, sa[i], sa[i-1], k) ? p-1: p++;
       }
       m = p;
    }
    if (x != rank) memcpy(rank, x, sizeof(int)*n);
}
void gen_height(char *str, int n, int *sa, int *rank, int *height) {
    int i, j, k;
    
    height[0] = 0;
    k = 0;
    for (i = 0; i < n-1; ++ i) {
       if (k) -- k;
       j = rank[i]-2;
       if (j == -1) continue;
       for (j = sa[j]; str[i+k] == str[j+k]; ) {
             ++ k;
       } 
       height[rank[i]-1] = k;
    }
}
int max_rectangle(int *height, int n) {
   int i, j, left, right, cur, top = -1;
   int result = 0; 
    
   height[n] = 0;
   stack[++top] = 0;
   for (i = 0; i <= n; ++ i) {
       while (top > -1 && height[i] < height[stack[top]]) {
           cur = stack[top--];
           left = (top > -1? cur-stack[top]: cur+1) * height[cur];
           right = (i - cur - 1) * height[cur];
           result = max(result, left+right+height[cur]);
       }
       stack[++top] = i;
   }
   return max(result, n-1); 
}
int main() {
    int n, result;
    scanf("%s", str);
    n = strlen(str);
    gen_sa(str, n+1, sa, rank);
    gen_height(str, n+1, sa, rank, height);
    result = max_rectangle(height, n+1);
    printf("%d\n", result);
}
