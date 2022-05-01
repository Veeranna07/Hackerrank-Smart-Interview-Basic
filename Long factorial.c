/*

                Long factorial
                Given a non-negative number - N, print N!

Input Format
First and only line of input contains a number - N.

Constraints
0 <= N <= 20

Output Format
Print factorial of N.

Sample Input 0
3

Sample Output 0
6

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
