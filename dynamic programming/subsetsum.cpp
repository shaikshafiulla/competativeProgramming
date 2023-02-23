#include<bits/stdc++.h>
using namespace std;
//memoization
bool f(int indx,int target,vector<int>& vec,vector<vector<int>>& dp)
{
    if(target == 0) return true;
    if(indx==0) return (vec[0]==target);
    if(dp[indx][target]!=-1) return dp[indx][target];
    bool left = f(indx-1,target,vec,dp);
    bool right = false;
    if(vec[indx]<=target){
        right = f(indx-1,target-vec[indx],vec,dp);
    }

    return dp[indx][target] = (left || right);
}
int main(){
    int n;
    cin>>n;
    vector<int> vec;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        vec.push_back(x);
    }
    int target;
    cin>>target;
    vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
    if(f(n-1,target,vec,dp)) cout<<"true";
    else cout<<"false";
}