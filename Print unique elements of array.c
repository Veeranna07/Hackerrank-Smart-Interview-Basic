/*

        Print unique elements of array
        Print unique elements of the array in the same order as they appear in the input.
        Note: Do not use any inbuilt functions/libraries for your main logic.

Input Format
First line of input contains a single integer N - the size of array and second line contains array elements.

Constraints
1 <= N <= 100
0 <= ar[i] <= 109

Output Format
Print unique elements of the array.

Sample Input 0
7
5 4 10 9 21 4 10

Sample Output 0
5 9 21

Explanation 0
Self Explanatory.

*/

#include<stdio.h>
#include<stdlib.h>
int element(int arr[],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(arr[i]==arr[j] && i!=j)
                break;
        }
        if(j==n)
        {
            printf("%d ",arr[i]);
        }
    }
    return -1;
}

int main()
{
    int i,n;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    element(arr,n);
}
