/*

                Harshad numbers
                Given an integer N, check whether it is a Harshad number or not.
                Note: A Harshad number is an integer, that is divisible by the sum of its digits.

Input Format
First and only line of input contains a integer - N.

Constraints
1 <= N <= 109

Output Format
Print "Yes" if the number is a Harshad number, "No" otherwise.

Sample Input 0
18

Sample Output 0
Yes

Explanation 0
18 / (1 + 8) = 2
As 18 is divisible by the sum of its digits, it is a Harshad number.

*/

#include<stdio.h>
int main()
{
    int long long n,n1,rem=0,sum=0;
    scanf("%lld",&n);
    n1=n;
    while(n>0)
    {
        rem=n%10;
        sum=sum+rem;
        n=n/10;
    }
    if(n1%sum==0)
        printf("Yes",n1);
    else
        printf("No",n1);
}
