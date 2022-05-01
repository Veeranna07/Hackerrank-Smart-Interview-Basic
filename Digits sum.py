'''

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

'''
n=int(input())
sum=0
m=0
while n!=0:
    m=n%10
    sum+=m
    n//=10
print(sum)
