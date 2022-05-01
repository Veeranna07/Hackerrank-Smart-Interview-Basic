/*

                    Occurrence of a character
                    Given a sentence S and a character ch, count occurrence of the given character in the sentence

Input Format
First line of input contains a sentence - S and second line of input contains a single lowercase character - ch.

Constraints
1 <= len(S) <= 100

Output Format
Print count of the given character in the sentence.

Sample Input 0
Data Structures & Algorithms
s

Sample Output 0
2

Explanation 0
Self Explanatory

*/

#include<stdio.h>
int main()
{
    char s[1000],c;
    int i,count=0;
    gets(s);
    c=getchar();
    for(i=0;s[i];i++)
        if(s[i]==c)
            count++;
    printf("%d",count);
}
