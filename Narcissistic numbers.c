/*

                Narcissistic numbers
                Given an integer N, check whether it is a Narcissistic number or not.
                Note: A narcissistic number is a number that is the sum of its own digits each raised to the power of the number of digits

Input Format
First and only line of input contains a integer - N.

Constraints
0 <= N <= 109

Output Format
Print "Yes" if the number is Narcissistic number, "No" otherwise.

Sample Input 0
8208

Sample Output 0
Yes

Explanation 0
84 + 24 + 04 + 84 = 8208

*/

#include<stdio.h>
int main()
{
    int long long n,ori,rem,sum=0,digit=0;
    scanf("%lld",&n);
    ori=n;
    while(n!=0)
    {
        digit++;
        n=n/10;
    }
    n=ori;
    while(n!=0)
    {
        rem=n%10;
        sum=sum+pow(rem,digit);
        n=n/10;
    }
    if(sum==ori)
        printf("Yes",ori);
    else
        printf("No",ori);
}
