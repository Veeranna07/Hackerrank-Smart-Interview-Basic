#include<stdio.h>
int main()
{
	int t,c,i;
	long n;
	scanf("%d",&t);
	while(t--)
	{
		c=0;i=1;
		scanf("%ld",&n);
		while(n/pow(5,i)>=1)
		{
			c=c+(int)(n/pow(5,i));
			i=i+1;
		}
		printf("%d\n",c);
	}
}
