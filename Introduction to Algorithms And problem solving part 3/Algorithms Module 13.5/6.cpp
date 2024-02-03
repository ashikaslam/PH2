//   problem link    https://cses.fi/problemset/task/1193

#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=10005;
int grid[N][N];
bool visited[N][N];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int level[N][N];
bool insidegrd(pair<int,int>src);
bool not_block(pair<int,int>src);
bool bfs(pair<int,int>src);
void path_printer();
pair<int,int> src,dst;
pair<int,int>parent[N][N];
void path_printer();
int main()
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {

            grid[i][j]=1;
        }
    }
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        string a;
        cin>>a;
        for(int j=0; j<m; j++)
        {
            if(a[j]=='.')grid[i][j]=0;
            else if(a[j]=='A')
            {
                grid[i][j]=0;
                src= {i,j};
            }
            else if(a[j]=='B')
            {
                grid[i][j]=0;
                dst= {i,j};
            }
        }
    }
    if(!bfs(src))
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES"<<endl;
    cout<<level[dst.first][dst.second];
    cout<<endl;
    path_printer();
    return 0;
}
bool bfs(pair<int,int>src)
{
    visited[src.first][src.second]=true;
    queue<pair<int,int>>q;
    q.push(src);
    level [src.first][src.second]=0;
    while(!q.empty())
    {
        pair<int,int>head;
        head=q.front();
        q.pop();
        int x=head.first;
        int y=head.second;
        for(int i=0; i<4; i++)
        {
            pair<int,int> newnode= {x+dx[i],y+dy[i]};
            if(insidegrd(newnode)&&not_block(newnode)&&
                    visited[newnode.first][newnode.second]==false)
            {
                level[newnode.first][newnode.second]=level[x][y]+1;
                visited[newnode.first][newnode.second]=true;
                parent[newnode.first][newnode.second]= {x,y};
                q.push(newnode);
                if(newnode==dst)
                {
                    return true;
                }
            }
        }
    }
    return false;
}
bool insidegrd(pair<int,int>src)
{
    if(src.first<n&&src.first>=0&&src.second<m&&src.second>=0)return true;
    return false;
}
bool not_block(pair<int,int>src)
{
    if(grid[src.first][src.second]!=1)return true;
    return false;
}
void path_printer()
{
    queue<pair<int,int>>q;
    stack<char>st;
    q.push(dst);
    while(q.front()!=src)
    {
        pair<int,int>head=q.front();
        q.pop();
        if(head.first-parent[head.first][head.second].first==-1
                &&head.second-parent[head.first][head.second].second==0)
            st.push('U');
        else if(head.first-parent[head.first][head.second].first==1
                &&head.second-parent[head.first][head.second].second==0)
            st.push('D');
        else if(head.first-parent[head.first][head.second].first==0
                &&head.second-parent[head.first][head.second].second==1)
            st.push('R');
        else if(head.first-parent[head.first][head.second].first==0
                &&head.second-parent[head.first][head.second].second==-1)
            st.push('L');
        q.push(parent[head.first][head.second]);
    }
    while(!st.empty())
    {
        cout<<st.top();
        st.pop();
    }
}




