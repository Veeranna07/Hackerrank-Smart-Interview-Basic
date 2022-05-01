/*

                  Number reverse
                  Given a number N, reverse the number.

Input Format
First and only line of input contains a integer - N.

Constraints
-1018 <= N <= 1018

Output Format
Print the reversed number.

Sample Input 0
1344

Sample Output 0
4431

*/

#include <stdio.h>
int main()
{
    long long num,n,rem=0,rev=0;
    scanf("%lld",&num);
    n=num;
    while(n!=0)
    {
        rem=n%10;   
        rev=rev*10+rem;
        n=n/10;
    }
        printf("%lld",rev);   
}
