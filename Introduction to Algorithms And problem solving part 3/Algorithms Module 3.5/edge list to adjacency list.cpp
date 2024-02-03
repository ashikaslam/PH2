#include <bits/stdc++.h>
using namespace std;
int main()
{
    int node;
    int edge;
    node = 4;
    edge = 4;
    vector<int> a[node];
    for (int i = 0; i < edge; i++)
    {
        int n1;
        int n2;
        cin >> n1 >> n2;
        a[n1].push_back(n2);
        a[n2].push_back(n1);
    }
    for (int i = 0; i<node; i++)
    {
        cout << i << " ->> ";
        for (auto j : a[i])
        {
            cout << j << " ";
        }
        cout<<"\n";
    }
    return 0;
}
/*
0 1
1 2
2 3
3 1

*/