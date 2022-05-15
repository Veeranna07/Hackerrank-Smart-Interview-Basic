#include<stdio.h>
int main()
{
    int g,b,x=1,y=1;
    while(x!= -1 && y!=-1)
    {
        scanf("%d%d",&g,&b);
        x=g;
        y=b;
        if(x!=-1 && y!=-1)
        {
            if(g==b)
            {
                if(g==0)
                printf("0\n");
                else
                printf("1\n");
            }
            else
            {
                if(g>b)
                {
                    x=g;
                    y=b;
                }
                else
                {
                    x=b;
                    y=g;
                }
                if((x%(y+1))==0)
                printf("%d\n",(x/(y+1)));
                else
                printf("%d\n",(x/(y+1))+1);
            }
        }
    }
}
