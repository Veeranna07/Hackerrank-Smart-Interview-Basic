/*

                      Hollow rectangle pattern
                      Print hollow rectangle pattern using '*'. See example for more details.

Input Format
Input contains two integers W - width of the rectangle and L - length of the rectangle.

Constraints
2 <= W <= 50
2 <= L <= 50

Output Format
For the given integers W and L, print the hollow rectangle pattern.

Sample Input 0
5 4

Sample Output 0
*****
*   *
*   *
*****

Explanation 0
Self Explanatory

*/

#include<stdio.h>
int main()
{
    int i,j,row,col;
    scanf("%d %d",&col,&row);
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(i==0 || i==row-1 || j==0 || j==col-1)
                printf("*");
            else
                printf(" ");
        }
    printf("\n");
    }
}
