#include <stdio.h>
int main()
{
    int n,min,max,countmin=0,countmax=0; 
    scanf("%d",&n);
    int *score=malloc(sizeof(int)*n);
    for(int score_i=0;score_i<n;score_i++)
       scanf("%d",&score[score_i]);
       
    min=max=score[0];
    for (int i=1;i<n;i++)
    {
        if (score[i]>max)
        {
            countmax++;
            max=score[i];
        }
        if (score[i]<min)
        {
            countmin++;
            min = score[i];
        }
    }
    printf("%d %d",countmax,countmin);
}
