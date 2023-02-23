#include<bits/stdc++.h>
using namespace std;
//memoization
bool f(int indx,int target,vector<int>& vec)
{
    if(target == 0) return true;
    if(indx==0) return (vec[0]==target);
    //if(dp[indx][target]!=-1) return dp[indx][target];
    bool left = f(indx-1,target,vec);
    bool right = false;
    if(vec[indx]<=target){
        right = f(indx-1,target-vec[indx],vec);
    }

    return (left || right);
}
int main(){
    int n;
    cin>>n;
int totalsum = 0;
    vector<int> vec;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        totalsum +=x;
        vec.push_back(x);
    }
    int target = totalsum/2;
    //vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
    if(f(n-1,target,vec)) cout<<"true";
    else cout<<"false";
}
//we have to check weather we can able to partiton the array to 2 equal subsets