#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long n,ans;
        scanf("%lld",&n);
        ans=192+(n-1)*250;
        printf("%lld\n",ans);
    }
}
