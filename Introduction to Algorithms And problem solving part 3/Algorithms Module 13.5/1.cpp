#include<bits/stdc++.h>
using namespace std;
const int N=100;
int level[N];
bool visited[N];
int parent[N];
vector<int>adja[N];
int n,m;
void dfs(int src);
int main()
{
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int u,v;
        cin>>u>>v;
        adja[u].push_back(v);
        adja[v].push_back(u);
    }
    int src=1;
    level[src]=0;
    dfs(src);
    cout<<level[n]<<endl;

    int now =n;
    while(now!=1)
    {
        cout<<now<<" ";
        now=level[now];
    }
    cout<<now;
    return 0;
}
void dfs(int src)
{
    visited[src]=true;
    for(auto j:adja[src])
    {
        if(visited[j]==false)
        {
            level[j]=level[src]+1;
            parent[j]=src;
            dfs(j);
        }
    }
}
