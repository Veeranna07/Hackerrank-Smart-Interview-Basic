/*

                      Palindromic right-angled triangle pattern
                      Print palindromic right-angled triangle pattern using characters. See example for more details.

Input Format
First and only line of input contains a integer N - size of the pattern.

Constraints
1 <= N <= 26

Output Format
For the given integer N, print the palindromic right-angled triangle pattern.

Sample Input 0
5

Sample Output 0
A 
A B A 
A B C B A 
A B C D C B A 
A B C D E D C B A

Explanation 0
Self Explanatory

*/

#include<stdio.h>
int main()
{
    int i,j,r,c=0;
    scanf("%d",&r);
    for(i=0;i<2*r;i=i+2)
    {
        for(j=0;j<=i;j++)
        {
            printf("%c ",'A'+c);
            if(j<i/2)
                c++;
            else
                c--;
        }
        c=0;
        printf("\n");
    }
}
