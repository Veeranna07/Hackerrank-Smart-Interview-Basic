#include<bits/stdc++.h>
using namespace std;
vector<int>g[100000];
bool  vis[100000];
int cn,v1;

void dfs(int s)
{
    vis[s]=1;
    for(int i=0; i<g[s].size(); i++)
    {
        int x=g[s][i];
        if(vis[x]!=0)
        {
            v1=1;
            break;
        }
        else
        {
            cn++;
            dfs(x);
        }

    }
}

int main()
{
    int n,e,u,v,sr,c=0;
    cin >> n >> e;
    for(int i=0; i<e; i++)
    {
        cin>>u>>v;
        if(c==0)
        {
            sr=u;
            c=1;
        }
        g[u].push_back(v);
    }
    v1=0,cn=1;
    vis[sr]=1;
    dfs(sr);
    if((e==n-1)&&(v1==0)&&(cn==n))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}
