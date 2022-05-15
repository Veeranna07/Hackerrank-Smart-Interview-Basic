#include<stdio.h>
int main()
{
    int n;
    while(scanf("%d",&n)==1)
        (n%10)?(printf("1\n%d\n",n%10)):(printf("2\n"));
}
