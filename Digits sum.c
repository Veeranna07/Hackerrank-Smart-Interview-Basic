/*

                        Digits sum
                        Given a non-negative integer - N, print the sum of digits of the given number.

Input Format
First and only line of input contains a non-negative integer N.

Constraints
0 <= length(N) <= 103

Output Format
Print the sum of digits of the given number.

Sample Input 0
164

Sample Output 0
11

Explanation 0
Self Explanatory

*/

#include<stdio.h>
int main()
{
    int n,m=0,sum=0;
    scanf("%d",&n);
    while(n!=0)
    {
        m=n%10;
        sum=sum+m;
        n=n/10;
    }
    printf("%d",sum);
}
