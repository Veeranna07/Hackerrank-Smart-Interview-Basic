#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int a[n];
    int aller;
    int sum=0;
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
        if(i==k)
            aller=a[i];
        else
            sum+=a[i];
    }
    int part=sum/2;
    int charg;
    scanf("%d",&charg);
    if(part==charg)
        printf("Bon Appetit\n");
    else
        printf("%d\n",charg-part);
}
