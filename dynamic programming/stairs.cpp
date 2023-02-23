/*
count all possible ways to reach nth stair
f(n)-->   sumof (f(n-1) and f(n-2))

*/
#include<bits/stdc++.h>
using namespace std;
int n;
int dp[100];
//memoization 
int rec(int n)
{
    if(n==0) return 1;
    if(n==1) return 1;
    if(dp[n]!=-1) return dp[n];
    int left = rec(n-1);
    int right = rec(n-2);
    return dp[n] = (left + right);
}
int main(){
    cin>>n;
    memset(dp,-1,sizeof(dp));
    cout<<rec(n);
}