#include <stdio.h>
int main()
    {
    int n,p,j=0,a[100000];
    scanf("%d %d",&n,&p);
    for (int i=0;i<=n;i++)
        if (i%2==0)
        {
            j++;
            a[i]=j;
            a[i+1]=j;
        }
    if (a[p]-1<j-a[p]) 
    printf("%d",a[p]-1);
    else 
    printf("%d",j-a[p]);
}
