#include<bits/stdc++.h>
using namespace std;
int rec(int level,auto &move,int n){
    if(level>n) return 0 ;
    if(level==n){
        // for(auto i:move){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        return 1;
    }   
    int ans = 0;
    for(int s = 1;s<=3;s++){
       if(s+level<=n){
        //move.emplace_back(s);
        int a = rec(s+level,move,n);
        ans+=a;
        //move.pop_back();
       }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> ans;
    vector<int> move;
    cout<<rec(0,move,n);
    // for(int i=0;i<ans.size();i++){
    //     for(int j=0;j<ans[i].size();j++){
    //         cout<<ans[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
}