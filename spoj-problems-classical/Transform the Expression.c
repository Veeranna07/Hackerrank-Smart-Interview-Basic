#include<stdio.h>
#include<string.h>
int top=-1;
char stack[200];

void push(int data)
{
    stack[++top]=data;
}

char pop()
{
    char data=stack[top];
    top--;
    return data;
}

int main()
{
    char expr[401],ans;
    int t,i,len;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",expr);
        len=strlen(expr);
        for(i=0;i<len;i++)
        {
            if(isalpha(expr[i]))
               printf("%c",expr[i]);
            else if(expr[i]=='(')
                        push('(');
            else if(expr[i]==')')
            { while(stack[top]!='(')
                     printf("%c",pop());
                pop();

            }
            else if(expr[i]=='^')
            {
                while(stack[top]=='^')
                    printf("%c",pop());
                push(expr[i]);
            }
            else if(expr[i]=='/'||expr[i]=='*')
            {
                while(stack[top]=='/'||stack[top]=='*'||stack[top]=='^')
                    printf("%c",pop());
                push(expr[i]);
            }
            else if(expr[i]=='+'||expr[i]=='-')
            {
            	while(stack[top]!='(')
            	printf("%c",pop());
            	push(expr[i]);
            }
            }
             printf("\n");
        }
 }
