/*

                     Print pyramid pattern
                     Print pyramid pattern using '*'. See example for more details.

Input Format
First and only line of input contains a single integer N - the size of the pyramid.

Constraints
1 <= N <= 50

Output Format
For the given integer, print pyramid pattern.

Sample Input 0
5

Sample Output 0
    *
   ***
  *****
 *******
*********

Explanation 0
Self Explanatory

*/

#include<stdio.h>
int main()
{    
    int i,j,n,k;
    scanf("%d",&n);
        for(i=n;i>=1;i--)
        {
            for(j=i;j>=2;j--)
            {
                printf(" ");
            }
            for(k=1;k<=2*(n-i+1)-1;k++)
            {
                printf("*");
            }
        printf("\n");
        }
}
