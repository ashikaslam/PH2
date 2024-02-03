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
        {
            a[i][j] = 0;
        }
    }
    for (int i = 0; i < edge; i++)
    {
        int n1;
        int n2;
        cin >> n1 >> n2;
        a[n1][n2] = 1;
        a[n2][n1] = 1;
    }
    for (int i = 0; i < node; i++)
    {
        for (int j = 0; j < node; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}