#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char s[30001];
int sublens[30001] = { 0 };

void longestsubstr(int pos) {
    int i, max = 0;
    for (i = 0; i < pos; i++) {
        if (s[i] != s[pos]) sublens[i] = 0;
        else {
            sublens[i] = sublens[i+1] + 1;
            if (i + sublens[i] > pos) sublens[i] = pos - i;
            if (sublens[i] > max) max = sublens[i];
        }
    }
    sublens[pos] = max;
}

int main() {
    int t, t1;
    scanf("%d", &t);
    for (t1 = 0; t1 < t; t1++) {
        int n, a, b, sublen, i, j, temp;
        scanf("%d %d %d", &n, &a, &b);
        scanf("%s", s);
        int ar[30001];
        for (i = 0; i < n; i++) {
            ar[i] = 0x7FFFFFFF;
            sublens[i] = 0;
        }
        for (i = n - 1; i >= 1; i--) longestsubstr(i);
        ar[0] = a;
        for (i = 1; i < n; i++) {
            if (ar[i-1] + a < ar[i]) ar[i] = ar[i-1] + a;
            sublen = sublens[i];
            temp = ar[i-1] + b;
            for (j = 0; j < sublen; j++) if (temp < ar[i+j]) ar[i+j] = temp;
        }
        printf("%d\n", ar[n-1]);
    }
}
