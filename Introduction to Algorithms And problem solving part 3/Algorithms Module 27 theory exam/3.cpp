#include<bits/stdc++.h>
using namespace std;
vector<int>sqnum;
int a;
int solv(int target);
int main()
{
    cin>>a;
    for(int i=1; i<=a; i++)
        if(sqrt(i)==floor(sqrt(i)))sqnum.push_back(i) ;
    cout<<solv(a);
    return 0;
}
int solv(int target)
{
    if(target%sqnum.back()==0)return target/sqnum.back();
    sqnum.pop_back();
    solv(target);
}
