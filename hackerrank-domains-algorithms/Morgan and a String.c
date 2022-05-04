#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char str1[100002] = {0};
char str2[100002] = {0};

int main() 
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%s", str1);
        scanf("%s", str2);

        int len1 = strlen(str1);
        int len2 = strlen(str2);
        str1[len1++] = 'z';
        str2[len2++] = 'z';
        str1[len1] = '\0';
        str2[len2] = '\0';

        int i = 0, j = 0;
        while(str1[i] != 'z' || str2[j] != 'z')
        {
            if(str1[i] < str2[j])
            {
                printf("%c",str1[i]);
                i++;
            }
            else if(str1[i] > str2[j])
            {
                printf("%c", str2[j]);
                j++;
            }
            else
            {
                int res = strcmp(str1 + i +1, str2 + j + 1);
                if(res <= 0)
                {
                    printf("%c", str1[i]);
                    i++;
                }
                else
                {
                    printf("%c", str2[j]);
                    j++;
                }
            }
        }
        printf("\n");
    }
}
