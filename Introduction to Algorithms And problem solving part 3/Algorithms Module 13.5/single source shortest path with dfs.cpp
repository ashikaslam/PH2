#include<bits/stdc++.h>
using namespace std;
const int N=1000;
const int inF=1000000;
int dist[N];
vector<int>adj[N];
void dfs(int src,int d)
{
    dist[src]=d;
    for (int i:adj[src])
    {
        if(dist[i]>dist[src]+1)
        {
            dist[i]=dist[src]+1;
            dfs(i,dist[src]+1);
        }
    }

}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0; i<=n; i++)
    {
        dist[i]=inF;
    }
    for(int i=0; i<m; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int src=7;
    dfs(src,0);
    for(int i=1; i<=n; i++)cout<<dist[i]<<" ";
    return 0;
}
