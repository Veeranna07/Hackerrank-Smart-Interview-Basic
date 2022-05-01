/*

               Right-angled triangle pattern 2
               Print right-angled triangle pattern. See example for more details.

Input Format
First line of input contains a single integer N - the size of the triangle.

Constraints
1 <= N <= 50

Output Format
For the given integer, print the right-angled triangle pattern.

Sample Input 0
5

Sample Output 0
1
2 6
3 7 10
4 8 11 13
5 9 12 14 15

Explanation 0
Self Explanatory

*/

#include<stdio.h>
int main()
{
    int i,j,k,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        k = i;
        for(j=1;j<=i;j++)
        {
            printf("%d ",k);
            k +=n-j;
        }
        printf("\n");
    }
}
