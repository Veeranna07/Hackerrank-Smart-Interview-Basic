#include <stdio.h>
int main()
{
    int n,a[100],temp;
    float minus=0,zeros=0,plus=0;
    scanf("%d",&n);
    for(temp=0;temp<n;temp++)
    {
        scanf("%d",&a[temp]);
        if(a[temp]>0)
            plus++;    
        else if(a[temp]==0)
            zeros++;    
        else
            minus++;    
    }
    printf("%.3f\n%.3f\n%.3f\n",plus/n,minus/n, zeros/n);
}
