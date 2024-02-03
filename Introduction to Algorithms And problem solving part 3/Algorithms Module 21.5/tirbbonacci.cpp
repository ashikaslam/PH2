/*#include<bits/stdc++.h>
using namespace std;
int dp[105];
int main()
{
    int n;
    cin>>n;
    dp[1]= 1;
    dp[2]= 1;
    dp[3]= 1;
    for(int i =4; i<=n; i++)
        dp[i] =  dp[i-1]+dp[i-2]+dp[i-3];
    cout<<dp[n];
}
*/

// now withe recursion

#include<bits/stdc++.h>
using namespace std;
long long  dp[105];
int tribonacci(int n)
{
// base case
    if(n<=3)return 1;

// if the current state is solve then return the result

    if(dp[n]!=0)return dp[n];

// solve the current state

    int ans = tribonacci( n -1)+tribonacci( n-2)+ tribonacci( n -3);
    dp[n]=ans;
    return ans;
}
int main()
{
    int n;
    cin>>n;
    cout<<tribonacci(n);
}



