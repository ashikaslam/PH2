#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int visited[N];
vector<int>adjList[N];
void dfs(int src);
void bfs(int src);
bool x=false;
int parent[N];
int pont;
void printer();
int main()
{
    int vertex;
    int edge;
    cin>>vertex>>edge;
    for(int i=0; i<N; i++)
    {
        visited[i]=0;
    }
    for(int i=0; i<edge; i++)
    {
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
    }
    for(int i=1; i<=vertex; i++)
    {
        if(visited[i]==false)
        {
            dfs(i);
            if(x==true)
            {
                for(int i=1;i<vertex;i++)cout<<parent[i]<<" ";
                return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE";
    return 0;
}
void dfs(int src)
{
    visited[src]=0;
    for(int i:adjList[src])
    {
        if(visited[i]==0)
        {
            parent[i]=src;
            dfs(i);
        }
        if(visited[i]==1)
        {
            x=true;
            parent[i]=src;
            pont=i;
            return;
        }
    }
    visited[src]=2;
}
void printer()
{
    queue<int>q;
    stack<int>st;
    q.push(pont);
    while(1)
    {
        st.push(q.front());
        q.pop();
        q.push(parent[st.top()]);
        if(q.front()==pont)break;
    }
    int k=st.top();
    int siz=st.size()+1;
    cout<<siz<<endl;
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<k;

}
