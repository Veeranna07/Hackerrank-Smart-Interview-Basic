#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,k,sum=0; 
    scanf("%d %d",&n,&k);
    int *a = malloc(sizeof(int) * n);
    for(int a_i = 0; a_i < n; a_i++)
       scanf("%d",&a[a_i]);
       
       for (int i = 0; i < n; i++) 
        for (int j = i+1; j < n; j++) 
        {
            if ( (a[i]+a[j])%k == 0)
                sum++;
        }
    printf("%d\n",sum);
}
