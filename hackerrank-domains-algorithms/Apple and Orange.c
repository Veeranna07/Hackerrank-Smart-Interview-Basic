#include <stdio.h>
int main()
{
    int s,t,a,b,m,n,i,c1=0,c2=0,tmp;
    scanf("%d %d %d %d %d %d",&s,&t,&a,&b,&m,&n);
    for(i = 0; i < m; i++)
    {
        scanf("%d",&tmp);
        tmp=a+tmp;
        
        if(tmp>=s && tmp<=t)
            c1++;
    }

    for(i=0;i<n;i++)
    {
        scanf("%d",&tmp);
        tmp=b+tmp;
        
        if(tmp>=s && tmp<=t)
            c2++;
    }
    printf("%d\n%d",c1,c2);
}
