#include <bits/stdc++.h>
using namespace std;
int main()
{
    int node;
    int edge;
    node = 4;
    edge = 4;
    int a[node][node];
    for (int i = 0; i < node; i++)
    {
        for (int j = 0; j < node; j++)
            a[i][j] = 0;
    }
    vector<pair<int, int>> adl[node];
    for (int i = 0; i < node; i++)
    {
        int connected_node;
        cout << "how meny node are connected with this node?>>";
        cin >> connected_node;
        cout << "\n";
        for (int j = 0; j < connected_node; j++)
        {
            int cnode;
            int w;
            cin >> cnode >> w;
            adl[i].push_back({cnode, w});
        }
    }
    for (int i = 0; i < node; i++)
    {
        for (auto j : adl[i])
        {
            a[i][j.first] = j.second;
        }
        cout << "\n";
    }
    cout << " the matrix is \n";
    for (int i = 0; i < node; i++)
    {
        for (int j = 0; j < node; j++)
            cout<< a[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}
