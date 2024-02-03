#include<bits/stdc++.h>
using namespace std;
class work_happiness
{
public:
    int a,b,c;
};
class mex_using_x
{
public:
    int a,b,c;
    mex_using_x()
    {
        a=0;
        b=0;
        c=0;
    }
};
vector<work_happiness>all_days_activistes;
mex_using_x dp[100];
int sovle(int n,int x);
int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        all_days_activistes.push_back({a,b,c});
    }
    dp[0].a = all_days_activistes[0].a;
    cout<<max(sovle(n-1,1),sovle(n-1,2),sovle(n-1,3));
    return 0;
}
int sovle(int n,int x)
{
// base case
    if(n==0 && x == 1)



    }
