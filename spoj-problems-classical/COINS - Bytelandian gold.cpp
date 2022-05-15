#include<bits/stdc++.h>
#define ll long long
using namespace std;
unordered_map<ll, ll> mp;

ll solve(ll n) 
{
    if(n<2) 
        return n;

    if(mp.count(n)) 
        return mp[n];
    
    mp[n] = max(n, solve(n/2)+solve(n/3)+solve(n/4));
    return mp[n];
}

int main() 
{
    ll n;
    while(cin>>n)
    cout<<solve(n)<<'\n';
}
