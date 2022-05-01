#include <stdio.h>
int main() 
{
    int a[5];
    long sum=0;
    for(int i=0;i<5;i++)
    {
        scanf("%d",a+i);
        sum+=a[i];
    }
    
    int min=a[0];
    int max=a[0];
    for(int i=1;i<5;i++)
    {
        if(a[i]>max)
            max=a[i];
        if(a[i]<min)
            min=a[i];
    }
    printf("%ld %ld",sum-max,sum-min);
}
