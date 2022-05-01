/*

                  Count vowels and consonants
                  Given a string, print count of vowels and consonants in the string.

Input Format
Input contains a string S, consisting of lowercase and uppercase characters.

Constraints
1 <= len(S) <= 100

Output Format
Print count of vowels and consonants in the given string, separated by space.

Sample Input 0
aBxbbiAasPw

Sample Output 0
4 7

Explanation 0
Self Explanatory

*/

#include <stdio.h>
int main()
{
    char str[100];
    int i,vow,con;
    i=vow=con=0;
    
    gets(str);
    while (str[i]!='\0')
    {
        if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' || str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U')
              vow++;      
          else
            con++;
        i++;
    }
    printf("%d %d", vow,con);
}
