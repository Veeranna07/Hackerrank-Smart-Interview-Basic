#include <stdio.h>
int main()
{
    int x1,x2,v1,v2,flag=0; 
    scanf("%d %d %d %d",&x1,&v1,&x2,&v2);
    int d1 = x1, d2 = x2;
    
    if (d1 == d2) 
    {
        flag = 1;
    }
    
    for (int i = 0; flag == 0 && d1 <= d2; i++) 
    {
        d1 += v1;
        d2 += v2;
        
        if (d1 == d2) 
        {
            flag = 1;
            break;
        }
    }
    
    if (flag == 1) 
        printf("YES");
    else 
        printf("NO");
}
