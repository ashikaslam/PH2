#include<bits/stdc++.h>
using namespace std;
const int N=100;
int level[N];
bool visited[N];
int parent[N];
int admat[N][N];
int n,m;
void bfs(int src);
int main()
{

    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin>>admat[i][j];
        }
    }
    int src=1;
    level[src]=0;
    bfs(src);
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
void bfs(int src)
{
    level[src]=0;
    visited[src]=true;
    queue<int>q;
    q.push(src);
    while(!q.empty())
    {
        int head=q.front();
        q.pop();
        for(int i=1; i<=m; i++)
        {
            int now =admat[head][i];
            if(now!=0 && visited[i]==false)
            {
                level[i]=level[head]+1;
                parent[i]=head;
                visited[i]=true;
                q.push(i);
            }
        }
    }
}
