#include<bits/stdc++.h>
using namespace std;
//memoization
int dp[10][10];
void print(auto &vec){
    for(int i=0;i<vec.size();i++){
        for(int j=0;j<vec[i].size();j++) {
            cout<<vec[i][j]<<" ";
            }
        cout<<endl;
    }
}
int rec(int i,int j,auto &vec){
    if(i==0 && j==0) return vec[i][j];
    if(i<0 || j<0) return 100;
    //if(dp[i][j]!=-1) return dp[i][j];
    int left = vec[i][j]+rec(i,j-1,vec);
    int up = vec[i][j]+rec(i-1,j,vec);
    return min(left , up);
}
int main(){
    int n,m;
    cin >> n>>m;
    //memset(dp,-1,sizeof(dp));
    vector<vector<int>> vec(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int x;
            cin>>x;
            vec[i][j] = x;
        }
    }
    //print(vec);
    cout<<rec(n-1,m-1,vec);
}