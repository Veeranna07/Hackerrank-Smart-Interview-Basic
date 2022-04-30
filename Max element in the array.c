/*

         Max element in the array
         Find maximum element from the given array of integers.

Input Format
First line of input contains N - the size of the array and second line contains the elements of the array.

Constraints
1 <= N <= 100
-109 <= ar[i] <= 109

Output Format
Print the maximum element of the given array.

Sample Input 0
5
-2 -19 8 15 4

Sample Output 0
15

Explanation 0
Self Explanatory
/*


#include<stdio.h>
int main()
{
    int n,i,arr[100];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=1;i<n;i++)
    {
        if(arr[0]<arr[i])
        {
            arr[0]=arr[i];
        }
    }
    printf("%d",arr[0]);
        
}
