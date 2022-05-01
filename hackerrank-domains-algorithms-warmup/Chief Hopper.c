#include <stdio.h>
int main()
{
    int b[100000],n,i,ans=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&b[i]);
    
    for(i=n-1;i>=0;i--)
        ans=(ans+b[i])/2+(ans+b[i])%2;
    printf("%d",ans);
}
