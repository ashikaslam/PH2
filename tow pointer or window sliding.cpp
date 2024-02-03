#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>a;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }
    int k;
    cin>>k;
    int sum=0,l=0,r=0,ans=-1;
    while(r<n)
    {
        sum+=a[r];
        if(r-l+1<k)r++;
        else if(r-l+1==k)
        {
            ans=max(sum,ans);
            sum-=a[l];
            r++;
            l++;
        }
    }
    cout<<ans;
    return 0;
}
