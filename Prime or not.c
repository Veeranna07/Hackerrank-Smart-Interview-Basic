/*

                 Prime or not
                 Given a positive integer N, check whether the number is prime or not.

Input Format
First and only line of input contains a integer - N.

Constraints
1 <= N <= 1012

Output Format
Print "Yes" if the number is prime, "No" otherwise.

Sample Input 0
11

Sample Output 0
Yes

Explanation 0
Self Explanatory

*/

#include<stdio.h>
int main()
{
    int long long i,n,temp=0;
    scanf("%lld",&n);
    if(n==0 || n==1)
        temp=1;
    for(i=2;i<=n/2;i++)
        if(n%i==0)
        {
            temp=1;
    break;
        }
    
    if(temp==0)
        printf("Yes");
    else
        printf("No");
}
