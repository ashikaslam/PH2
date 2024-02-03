#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>edge_list;
vector<int>parent;
int find_parent(int x);
bool cycle=false;
void usnion(int a,int b);
int main()
{
    int n,m;
    cin>>n>>m;
    parent.resize(n+1,-1);
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        edge_list.push_back({u,v});
    }
    for(int i=0; i<edge_list.size(); i++)
    {
        pair<int,int>pr=edge_list[i];
        int a =pr.first;
        int b=pr.second;
        int parntA=find_parent(a);
        int parntB=find_parent(b);
        if(parntA==parntB )
        {
            cycle=true;
            break;
        }
        else
            usnion(a,b);
    }
    if(cycle)
        cout<<"YES";
    else
    {
        cout<<"NO"<<endl;
        cout<<parent[5];
    }
    return 0;
}
int find_parent(int x)
{
    if(parent[x]==-1)
        return x;
    return find_parent(parent[x]);
}
void usnion(int a,int b)
{
    int parntA=find_parent(a);
    int parntB=find_parent(b);
    parent[parntB] = parntA;
}
