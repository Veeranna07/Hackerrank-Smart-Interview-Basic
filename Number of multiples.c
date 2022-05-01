/*

                     Number of multiples
                     Given a positive integer - N, print the number of multiples of 3, 5 between [1, N].

Input Format
First and only line of input contains a positive integer - N.

Constraints
1 <= N <=1018

Output Format
Print the number of multiples of 3, 5 in range of 1 to N.

Sample Input 0
12

Sample Output 0
6

Explanation 0
Multiples of 3 and 5 in range of 1 to 12 are 3, 5, 6, 9, 10, 12.

*/

#include<stdio.h>
int main()
{
    int long long n,n1,n2;
    scanf("%lld",&n);
    n1=n/3+n/5;
    n2=n1-n/15;
    printf("%lld",n2);
}
