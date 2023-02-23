#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> vec;
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        vec.push_back(x);
    }
    int totsum = 0;
    for(int i:vec)totsum += i;
    vector<vector<bool>> dp(n+1,vector<bool>(totsum+1));
    for(int i=0;i<n;i++) dp[i][0] = true;
    if(vec[0]<=totsum) dp[0][vec[0]] = true;
    for(int indx = 1;indx<n;indx++){
        for(int target = 1;target<=totsum;target++){
            bool not_take = dp[indx-1][target];
            bool take = false;
            if(vec[indx]<=totsum) take = dp[indx-1][target-vec[indx]];
            dp[indx][target] = take|not_take;
        }
    }
    int mini = 1e9;
    for(int s1 =0;s1<totsum/2;s1++)
    mini = min(mini,abs((totsum-s1)-s1));
    cout<<mini;
}