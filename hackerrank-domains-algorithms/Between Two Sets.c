#include <stdio.h>
int main()
{
    int n,m; 
    scanf("%d %d",&n,&m);
    
    int *a = malloc(sizeof(int) * n);
    for(int a_i = 0; a_i < n; a_i++)
    {
       scanf("%d",&a[a_i]);
    }
    
    int *b = malloc(sizeof(int) * m);
    for(int b_i = 0; b_i < m; b_i++)
    {
       scanf("%d",&b[b_i]);
    }
    
    int count = 0;
       
    for(int x=1; x<=100; x++)
    {    
        int flag = 1;   
        for(int a_i = 0; a_i < n; a_i++)
        {
            for(int b_i = 0; b_i < m; b_i++)
            {
                if(x % a[a_i] || b[b_i] % x) flag = 0;
            }               
        }
        if(flag) count++;
    }
    printf("%d", count);
}
