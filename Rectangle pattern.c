/*

             Rectangle pattern
             Print rectangle pattern. See example for more details.

Input Format
First and only line of input contains a single integer N - the size of the rectangle.

Constraints
1 <= N <= 50

Output Format
For the given integer, print rectangle pattern as shown in example.

Sample Input 0
5

Sample Output 0
5432*
543*1
54*21
5*321
*4321

Explanation 0
Self Explanatory

*/

#include<stdio.h>
int main()
{
    int i,j,l;
    scanf("%d",&l);
    for(i=1;i<=l;i++)
    {
        for(j=l;j>=1;j--)
        {
            if(j!=i)
                printf("%d",j);
            else
                printf("*");
        }
        printf("\n");
    }
}
