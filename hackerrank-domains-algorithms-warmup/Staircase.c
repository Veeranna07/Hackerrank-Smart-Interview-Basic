#include <stdio.h>
int main()
{
    int i,j,h,stair;
    scanf("%d",&h);
    stair=h-1;
    
    for(i=0;i<h;i++)
    {
        for(j=0;j<h;j++)
        {
            if(j>=stair)
                printf("#");
                 else
                printf(" ");
        }
        stair -= 1;
        printf("\n");
    }    
}
