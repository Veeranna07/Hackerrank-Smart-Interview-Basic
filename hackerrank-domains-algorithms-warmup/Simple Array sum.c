#include <stdio.h>
int N;
int map[1000];
int main() 
{
    int n,arr[1000];
  long int sum =0;
    scanf("%d",&N);
    for(int i = 0; i<N; i++)
        {
      scanf("%d",&map[i]);
    }
    for(int i=0; i<N;i++)
        {
        sum += map[i];
    }  
    printf("%ld",sum);
}
