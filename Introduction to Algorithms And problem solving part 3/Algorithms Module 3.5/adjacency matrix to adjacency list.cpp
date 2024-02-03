#include <bits/stdc++.h>
using namespace std;
int main()
{
    int node;
    int edge;
    node = 7;
    edge = 6;
    int a[node][node];
    for (int i = 0; i < node; i++)
    {
        for (int j = 0; j < node; j++)
            cin >> a[i][j];
        cout << "\n";
    }
    vector<pair<int,int>> adl[node];
    cout << " the matrix is \n";
    for (int i = 0; i < node; i++)
    {
        for (int j = 0; j < node; j++)
            if (a[i][j] != 0)
            {
                adl[i].push_back({j,a[i][j]});
            }
    }
    for (int i = 0; i < node; i++)
    {
        cout << i << " ->> ";

        for (auto j : adl[i])
        {
            cout <<j.first<<" "<<j.second<<"     ";
        }
        cout << "\n";
    }
    return 0;
}
