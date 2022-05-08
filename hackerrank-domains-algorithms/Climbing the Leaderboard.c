#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,t,max_rank=0,cr,cs=0; 
    scanf("%d",&n);
    int *scores = malloc(sizeof(int) * n);
    for(int scores_i = 0; scores_i < n; scores_i++)
    {
        scanf("%d",&t);
        if(max_rank)
        {
            if(scores[max_rank-1]==t)
            {
                continue;  
            }
        }
        scores[max_rank++]=t;
    }
    cr=max_rank+1;
    int m; 
    scanf("%d",&m);
    int *alice = malloc(sizeof(int) * m);
    for(int alice_i = 0; alice_i < m; alice_i++)
    {
       scanf("%d",&alice[alice_i]);
    }
    int temp;
    for(int i=0;i<m;i++)
    {
        cs=alice[i];
        temp=cr;
        while(temp>0 && scores[--temp]<=cs ) cr=temp;
        printf("%d\n",cr+1);
    }
}
