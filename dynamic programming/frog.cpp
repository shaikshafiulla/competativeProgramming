/*memoization technique
    create a dp array of size equal to vector
    while returning the value store it in dp array
    during recursion call check for cache..
*/
// #include<bits/stdc++.h>
// using namespace std;
// int rec(auto &vec,int n,auto &dp)
// {

//     if(n==0) return 0;
//     //only 1 jump
//     if(dp[n]!=-1) return dp[n];
//     int j1 = rec(vec,n-1,dp)+abs(vec[n]-vec[n-1]);
//     //2 jumps
//     int j2 = INT_MAX;
//     if(n>1)
//     j2 = rec(vec,n-2,dp)+abs(vec[n]-vec[n-2]);
//     return dp[n] = min(j1,j2);
// }
// int main(){
//     int n;
//     cin>>n;
//     vector<int> vec;
//     for(int i=0;i<n;i++){
//         int x;
//         cin>>x;
//         vec.emplace_back(x);
//     }

//     //memoization
//     vector<int> dp(n,-1);
//     cout<<rec(vec,n-1,dp);
// }

// tabulation method
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> vec{10, 20, 30, 10};
    vector<int> dp(vec.size(), 0);
    for (int i = 1; i < vec.size(); i++)
    {
        int left = dp[i - 1] + abs(vec[i] - vec[i - 1]);
        int right = INT_MAX;
        if (i > 1)
        {
            right = dp[i - 2] + abs(vec[i] - vec[i - 2]);
        }
        dp[i] = min(left, right);
    }
    cout << dp[vec.size() - 1];
}