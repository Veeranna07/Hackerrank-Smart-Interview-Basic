/*

             Matrix column sum
             Given a matrix of size N x M, print column-wise sum, separated by a newline.

Input Format
The first line of input contains N, M - the size of the matrix. Its followed by N lines each containing M integers - elements of the matrix.

Constraints
1 <= N, M <= 100
-106 <= ar[i] <= 106

Output Format
Print column-wise sum of the matrix, separated by newline.

Sample Input 0
2 2
5 -1
19 8

Sample Output 0
24
7

Explanation 0
Self Explanatory.

*/

#include <stdio.h>
int main()
{
    int n,m,i,j,arr[100][100];
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        scanf("%d",&arr[i][j]);
    
  for(j=0;j<m;j++)
  {
      int sum=0;
      for(i=0;i<n;i++)
          sum=sum+arr[i][j];
      printf("%d\n",sum);
  }
}
