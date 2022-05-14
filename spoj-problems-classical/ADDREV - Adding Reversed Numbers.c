#include<stdio.h>

int rev(int n)
{
	int temp=0;
	while(n)
	{
		temp=(temp*10)+(n%10);
		n/=10;
	}
	return temp;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n1,n2;
		scanf("%d %d",&n1,&n2);
		printf("%d\n",rev(rev(n1)+rev(n2)));
		
	}
}
