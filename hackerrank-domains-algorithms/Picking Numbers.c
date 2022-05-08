#include <stdio.h>
#include <stdlib.h>
int answer(int *, int);

int main()
{
    int n,i,j,temp; 
    scanf("%d",&n);
    int *a = malloc(sizeof(int) * n);
    for(int a_i = 0; a_i < n; a_i++)
    {
       scanf("%d",&a[a_i]);
    }
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(a[j] < a[i])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    printf("%d",answer(a,n));
}

int answer(int a[],int n)
    {
    int i,j,count=0,max=0;
    for(i=0;i<n;i++)
        {
        count = 0;
        for(j=i+1;j<n;j++)
            {
            if((a[j]-a[i]==1)||(a[j]-a[i]==0))
                count++;
        }
        if(max<count)
            {
            max = count;
        }
        else{}
    }
    return max+1;
}
