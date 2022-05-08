#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    int arr[101];
    for(int i=0;i<101;i++)
    {
        arr[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        int j;
        scanf("%d",&j);
        arr[j] += 1;
    }
    int total=0;
    for(int i=0;i<101;i++)
    {
        if(arr[i]> 1)
        {
            if(arr[i] % 2 == 0) total += (arr[i] / 2);
            else total += ((arr[i]-1) / 2);
        }
    }
    printf("%d",total);
}
