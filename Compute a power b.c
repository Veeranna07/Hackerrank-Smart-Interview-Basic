/*

                       Compute a power b.
                       Given two integers a and b, compute a power b.
                       Note: Do not use any inbuilt functions/libraries for your main logic.

Input Format
First and only line of input contains two positive integers a and b.

Constraints
1 <= a <= 100
0 <= b <= 9

Output Format
Print a power b.

Sample Input 0
2 3

Sample Output 0
8

Explanation 0
Self Explanatory.

*/

#include<stdio.h>
int main()
{
    long long a,b,value=1;
    scanf("%lld %lld",&a,&b);
    while(b!=0)
    {
        value*=a;
        b--;
    }
    printf("%lld",value);
}
