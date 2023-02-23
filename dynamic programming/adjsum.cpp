#include<bits/stdc++.h>
using namespace std;
int n;
int dp[1000];
int rec(int indx,vector<int> &vec)
{
    //pruning step
    if(indx<0) return 0;
    if(indx==0) return vec[indx];
    if(dp[indx]!=-1) return dp[indx];
    int left = vec[indx]+rec(indx-2,vec);
    int right = rec(indx-1,vec);
    return dp[indx] = max(left,right);
}
int main(){
    cin>>n;
    vector<int> vec;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        int x;cin>>x;
        vec.push_back(x);
    }
    cout<<rec(n-1,vec);
}