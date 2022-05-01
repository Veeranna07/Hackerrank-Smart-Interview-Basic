/*

                         Transpose matrix
                         Given a matrix of size N x M, print transpose of the matrix.

Input Format
First line of input contains N, M - the size of the matrix. Its followed by N lines each containing M integers - elements of the matrix.

Constraints
1 <= N, M <= 100
-109 <= ar[i] <= 109

Output Format
Print the transposed of the given matrix.

Sample Input 0
2 2
5 -1
19 8

Sample Output 0
5 19
-1 8

Explanation 0
Self Explanatory

*/

#include <stdio.h>
int main()
{
    int n,i,j,m,arr[100][100];
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&arr[i][j]);
        
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
        {
            printf("%d ",arr[j][i]);
            if(j==n-1)
                printf("\n");
        }
}
