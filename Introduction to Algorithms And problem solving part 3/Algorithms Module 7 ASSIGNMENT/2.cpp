#include<bits/stdc++.h>
using namespace std;
int poweR(int base,int power);
int main()
{
    int n,p;
    cout<<"enter the base>>";
    cin>>n;
    cout<<"enter the power>>";
    cin>>p;
    cout<<"the result is>> ";
    cout<<poweR(n,p);
    return 0;
}
int poweR(int base,int power)
{
    if(power==1)return base;
    return base*poweR(base, power-1);
}
