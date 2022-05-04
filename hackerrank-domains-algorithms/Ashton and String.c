#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define N 100001
void merge(int*a,int*left,int*right,int left_size, int right_size);
void sort_a(int*a,int size);
void suffixSort(int n);
void LCP(int n);
char str[N]; 
int rank[N], pos[N], lcp[N];
int cnt[N], next[N]; 
int bh[N], b2h[N];

int main()
{
  char cc;
  int T,n,i;
  long long K,c,t,x,tt;
  double xx;
  scanf("%d",&T);
  while(T--)
  {
    scanf("%s%lld",str,&K);
    n=strlen(str);
    suffixSort(n);
    LCP(n);
    c=0;
    for(i=0;i<n;i++)
    {
      tt=c;
      c+=(lcp[i]+1+n-pos[i])*(long long)(n-pos[i]-lcp[i])/2;
      if(K<=c)
      {
        xx=(-1+sqrt(4*(2*(K-tt)+lcp[i]+lcp[i]*(long long)lcp[i])))/2;
        x=(long long)xx;
        t=K-tt-(lcp[i]+1+x)*(x-lcp[i])/2;
        if(!t)
          cc=str[pos[i]+x-1];
        else
          cc=str[pos[i]+t-1];
        break;
      }
    }
    printf("%c\n",cc);
  }
}

void merge(int*a,int*left,int*right,int left_size, int right_size)
{
    int i = 0, j = 0;
    while (i < left_size|| j < right_size) 
    {
        if (i == left_size) 
        {
            a[i+j] = right[j];
            j++;
            }
             else if (j == right_size) 
             {
                 a[i+j] = left[i];
                 i++;
              }
               else if (str[left[i]] <= str[right[j]]) 
               {
                   a[i+j] = left[i];
                   i++;
                }
                 else 
                 {
                     a[i+j] = right[j];
                     j++;
                }
            }
    return;
}

void sort_a(int*a,int size)
{
  if (size < 2)
    return;
  int m = (size+1)/2,i;
  int *left,*right;
  left=(int*)malloc(m*sizeof(int));
  right=(int*)malloc((size-m)*sizeof(int));
  for(i=0;i<m;i++)
    left[i]=a[i];
  for(i=0;i<size-m;i++)
    right[i]=a[i+m];
  sort_a(left,m);
  sort_a(right,size-m);
  merge(a,left,right,m,size-m);
  free(left);
  free(right);
  return;
}
 
void suffixSort(int n)
{

  int h,i,j,k;
  for (i=0; i<n; ++i)
  {
    pos[i] = i;
  }
  sort_a(pos, n);

 
  for (i=0; i<n; ++i)
  {
    bh[i] = i == 0 || str[pos[i]] != str[pos[i-1]];
    b2h[i] = 0;
  }
 
  for (h = 1; h < n; h <<= 1)
  {
    int buckets = 0;
    for (i=0; i < n; i = j)
    {
      j = i + 1;
      while (j < n && !bh[j]) j++;
      next[i] = j;
      buckets++;
    }
    if (buckets == n) break; 
    for (i = 0; i < n; i = next[i])
    {
      cnt[i] = 0;
      for (j = i; j < next[i]; ++j)
      {
        rank[pos[j]] = i;
      }
    }
 
    cnt[rank[n - h]]++;
    b2h[rank[n - h]] = 1;
    for (i = 0; i < n; i = next[i])
    {
      for (j = i; j < next[i]; ++j)
      {
        int s = pos[j] - h;
        if (s >= 0){
          int head = rank[s];
          rank[s] = head + cnt[head]++;
          b2h[rank[s]] = 1;
        }
      }
      for (j = i; j < next[i]; ++j)
      {
        int s = pos[j] - h;
        if (s >= 0 && b2h[rank[s]])
        {
          for (k = rank[s]+1; !bh[k] && b2h[k]; k++) b2h[k] = 0;
        }
      }
    }
    for (i=0; i<n; ++i)
    {
      pos[rank[i]] = i;
      bh[i] |= b2h[i];
    }
  }
  for (i=0; i<n; ++i)
  {
    rank[pos[i]] = i;
  }
}


void LCP(int n)
{
  int l=0,i,j,k;
  for(i=0;i<n;i++)
  {
    k=rank[i];
    if(!k)
      continue;
    j=pos[k-1];
    while(str[i+l]==str[j+l])
      l++;
    lcp[k]=l;
    if(l>0)
      l--;
  }
  lcp[0]=0;
  return;
}

