/*

             Compute N!
             Given a non-negative number - N, print N!

Input Format
First and only line of input contains a number - N.

Constraints
0 <= N <= 10

Output Format
Print factorial of N.

Sample Input 0
5

Sample Output 0
120

Explanation 0
Self Explanatory

*/

#include<stdio.h>
int main()
{
    int long long n,fact=1;
    int i;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
        fact=fact*i;
    printf("%lld",fact);
}
