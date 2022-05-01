#include <stdio.h>
int main() 
{
    int n,h,hm,c;
    scanf("%d", &n);
    c=0,hm=0;
    
    for(int idx=0;idx<n;idx++)
    {
        scanf("%d",&h);
        if (h>hm)
        {
            hm=h;
            c=1;
        }
        else if(h==hm)
            c++;
    }
    printf("%d", c);
}
