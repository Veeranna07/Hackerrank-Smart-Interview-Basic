#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long n,x;
        scanf("%lld",&n);
        long long rem=0;
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&x);
            rem=(rem+x%n)%n;
        }
        if(rem==0)
        printf("YES\n");
        else
        printf("NO\n");
    }
}
