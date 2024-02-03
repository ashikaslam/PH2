#include<bits/stdc++.h>
using namespace std;
class query
{
public:
    string s;
    int a,b;
};
vector<pair<int,int>>edge_list;
vector<int>parent;
int find_parent(int x);
bool cycle=false;
void usnion(int a,int b);
vector<query>qr;
vector<int>rankar;
void cycledec(int a,int b);
int main()
{
    int n,q;
    cin>>n>>q;
    for(int i =1; i<=n; i++)parent[i]=1;
    rankar.resize(n+1,1);
    while(q--)
    {
        string s;
        int u,v;
        cin>>s>>u>>v;
        qr.push_back({s,u,v});
    }
    for(auto j:qr)
    {
        int a =j.a;
        int b=j.b;
        string q = j.s;
        if(q == "union")
            usnion(a,b);
        else if(q == "get")
            cycledec( a,b) ;
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
    if(rankar[parntA]>=rankar[parntB])
    {
        parent[parntB] = parntA;
        rankar[parntA]=  rankar[parntA] +rankar[parntB];
    }
    else
    {
        parent[parntA] = parntB;
        rankar[parntB]=  rankar[parntB] +rankar[parntA];
    }

}
void cycledec(int a,int b)
{

    if(parent[a]==parent[b] &&parent[b]!=-1)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}
