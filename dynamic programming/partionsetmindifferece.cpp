/*
3
8 6 5
3
*/
#include<bits/stdc++.h>
using namespace std;
bool f(int indx,int target,int *a,int sum,vector<vector<bool>>& dp)
{
    if(target ==0) return dp[indx][target]=true;
    if(indx==0) return dp[indx][target]=(a[0]==target);
    if(dp[indx][target]!=false) return dp[indx][target];
    bool nottaken = f(indx-1,target,a,sum,dp);
    bool taken = false;
    if(a[indx]<=target) taken = f(indx-1,target-a[indx],a,sum,dp);
    return dp[indx][target] = (taken || nottaken);
}
void mindif(int n,int *a,int sum)
{
    vector<vector<bool>> dp(n,vector<bool>(sum,false));
    for(int i= 0;i<=sum;i++)
    {
        bool dummy = f(n-1,i,a,sum,dp);
    }
    int mini = 1e9;
    for(int i=0;i<=sum;i++){
        if(dp[n-1][i]==true)
        {
            int s2 = sum-i;
            mini = min(mini,abs(i-s2));
        }
    }
    cout<<mini;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    int sum = 0;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) sum += a[i];
 mindif(n,a,sum);
}