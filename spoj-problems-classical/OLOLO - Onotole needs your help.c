#include<stdio.h>
int main()
{
    int n,i;
    scanf("%d",&n);
    long long int arr[n];
    for(i=0;i<n;i++)
        scanf("%lld",&arr[i]);
    long long int a,ans;
    a=arr[0];
    for(i=1;i<n;i++)
    {
        ans=a^arr[i];
        a=ans;
    }
    printf("%lld\n",ans);
}
