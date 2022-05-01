/*

                  Natural numbers sum
                  Given a positive integer N, print the sum of 1st N natural numbers.

Input Format
First and only line of input contains a positive integer - N.

Constraints
1 <= N <= 104

Output Format
Print the sum of 1st N natural numbers.

Sample Input 0
4

Sample Output 0
10

Explanation 0
Self Explanatory

*/

#include <stdio.h>
int main()
{
    long long sum=0,i,n;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
        sum=sum+i;
    printf("%lld",sum);
}
