#include <stdio.h>
int main() 
{
    char t[10];
    scanf("%s",t);

   if(t[8]=='P') 
   {
     if(t[0]!='1' || t[1]!='2') 
     {
       t[0]++;
       t[1]+=2;
     }
   } 
   else 
   {
     if(t[0]=='1' && t[1]=='2') 
     {
       t[0]='0';
       t[1]='0';
     }
   }
   t[8]='\0';
   printf("%s\n", t);
}
