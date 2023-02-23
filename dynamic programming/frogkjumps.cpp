// #include<bits/stdc++.h>
// using namespace std;
// int k;
// int rec(int n,auto &vec,auto &dp){
//     if(n==0) return 0;
//     int minsteps = INT_MAX;
//     for(int j=1;j<=k;j++){
//         if(n-j>=0){
//         int jump = rec(n-j,vec,dp)+abs(vec[n]-vec[n-j]);
//         minsteps= min(minsteps,jump);
//          }
//     }
//     return minsteps;
// }
// int main(){
//     vector<int> vec{10,20,30,10};
//     cin>>k;
//     vector<int> dp(vec.size(),0);
//     cout<<rec(vec.size()-1,vec,dp);
// }

//memoization
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> vec{10,20,30,10};
    int k;
    cin>>k;
    vector<int> dp(vec.size(),0);  //dp[0] = 0
    int n = vec.size();
    for(int i=1;i<vec.size();i++)
    {
        int minsteps = INT_MAX;
        for(int j=1;j<=k;j++)
        {
            if(i-j>=0)
            {
                int jump = dp[i-j]+abs(vec[i]-vec[i-j]);
                minsteps= min(minsteps,jump);
            }
        }
        dp[i] = minsteps;
    }
    cout<<dp[vec.size()-1];
}