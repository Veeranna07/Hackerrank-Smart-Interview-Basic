#include<bits/stdc++.h>
using namespace std;

const double PIE = 3.14159;
const double zero = 0;

int main() 
{
    double l;
    cin>>l;
    while(l != zero) 
    {
        double area = l*l/(2.0*PIE);
        cout<<fixed<<setprecision(2)<<area<<endl;
        cin>>l;
    }
}
