#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,d,m,count=0; 
    scanf("%d",&n);
    int *squares=malloc(sizeof(int)*n);
    for(int squares_i = 0; squares_i < n; squares_i++)
       scanf("%d",&squares[squares_i]);
       scanf("%d %d",&d,&m);

    for (int i = 0; i < n; i++) 
    {
        int sum = 0;
        if (i + m <= n) 
        {
            for (int j = 0; j < m; j++) 
            {
                sum+=squares[i+j];
            }
            if (sum == d) 
            {
                count++;
            }
        }
    }
    printf("%d\n", count);
}
