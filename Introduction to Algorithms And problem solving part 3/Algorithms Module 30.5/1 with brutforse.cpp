#include<bits/stdc++.h>
using namespace std;
bool is_palindrome(string s)
{
    // base case
    if(s=="" || s.size()==1)
        return true;
    string small_str = s.substr(1, s.size()-2);
    return is_palindrome(small_str) && (s[0] == s.back());
}

int main()
{
    int n;
    cin>>n;
    vector<string>ar;
    for(int i=1; i<=n; i++)
    {
        string s;
        cin>>s;
        ar.push_back(s);
    }
    vector<string>ar2;
    ar2.push_back(ar[0]);
    for(int i=1; i<n; i++)
    {
        ar2.push_back(ar[i]);
        int l=ar2.size();
        for(int k=0; k<l-1; k++)
        {

            ar2.push_back(ar2[k]+ar[i]);
        }
    }
    int l=ar2.size();
    int maxx=0;
    for(int i=0; i<l; i++)
    {
        if(is_palindrome(ar2[i]))
        {
            int len=ar2[i].size();
            maxx=max(maxx,len);
        }
    };
    cout<<maxx;
    return 0;
}
