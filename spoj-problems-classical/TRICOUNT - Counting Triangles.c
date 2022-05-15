#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long n,s;
        scanf("%lld",&n);
        if(n%2==0)
        s=(n*(n+2)*((2*n)+1))/8;
        else
        s=((n*(n+2)*((2*n)+1))-1)/8;
        printf("%lld\n",s);
    }
}
