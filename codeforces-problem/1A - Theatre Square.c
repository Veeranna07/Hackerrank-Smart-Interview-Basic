
//NOTE : The following code shows "Compilation Error" in codeforces Website and works preety perfect on other coding platforms.

#include<stdio.h>
#include<math.h>

int main()
{
    double n,m,a;
    scanf("%lf %lf %lf", &n,&m,&a);
    printf("%1.lf\n", ceil(n/a)*ceil(m/a));
}#include<stdio.h>
int main()
{
    long long int x,y,z,a,b;
    scanf("%lld %lld %lld",&x,&y,&z);
    if(x%z==0)
    {
        a=(x/z);
    }
    else if(x%z!=0)
    {
        a=(x/z)+1;
    }
    if(y%z==0)
    {
        b=(y/z);
    }
    else if(y%z!=0)
    {
        b=(y/z)+1;
    }
    printf("%lld\n",a*b);
}
