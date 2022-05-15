#include<stdio.h>

int ph(int n)
{
    int ans=n;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
            n/=i;
            ans-=ans/i;
        }
    }
    if(n>1)
    ans-=ans/n;
    return ans;
}

int main()
{
    long long t,idd=0,b,n,temp,r,i,p,q,c,ans;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        printf("%d\n",ph(n));
    }
}
