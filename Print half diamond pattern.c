/*

                  Print half diamond pattern
                  Print half diamond pattern using '*'. See example for more details.

Input Format
First and only line of input contains a single integer N.

Constraints
1 <= N <= 50

Output Format
For the given integer, print the half diamond pattern.

Sample Input 0
5

Sample Output 0
*
**
***
****
*****
****
***
**
*

Explanation 0
Self Explanatory

*/

#include<stdio.h>
int main()
{
    int i,j,n,col=1;
    scanf("%d",&n);
    for(i=1;i<n*2;i++)
    {
        for(j=1;j<=col;j++)
            printf("*");
    
    if(i<n)
        col++;
    else
        col--;
        printf("\n");
    }
}
