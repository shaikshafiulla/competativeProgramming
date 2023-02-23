#include<bits/stdc++.h>
using namespace std;
void print(auto &vec){
    for(int i=0;i<vec.size();i++){
        for(int j=0;j<vec[i].size();j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
}
void rec(int level,int n,int *a,int target,auto &ans,vector<int> &move){
    if(target<0) return;
    if(level==n-1){
        if(target==0)
            ans.push_back(move);
        return;
    }
    move.push_back(a[level]);
    rec(level,n,a,target-a[level],ans,move);
    move.pop_back();
    rec(level+1,n,a,target,ans,move);
}
int main(){
    int a[5] = {2,1,5,3,8};
    int target = 6;
    vector<vector<int>> ans(0,vector<int>(0));
    vector<int> move;
    rec(0,5,a, target ,ans,move);
    print(ans);
}