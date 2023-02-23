#include<bits/stdc++.h>
using namespace std;
void rec(int i,int *a,auto &move,int n,auto &ans,int sum,int target)
{
    if(i>n) return;
        if(sum==target){
        for(auto i:move) cout<<i<<" ";
        cout<<endl;
        return;
    }
    move.push_back(a[i]);
    rec(i+1,a,move,n,ans,sum+a[i],target);
    move.pop_back();
    rec(i+1,a,move,n,ans,sum,target);
}
int main(){
    int a[] = {1,2,1};
    int target = 2;
    int n = 3;
    vector<int> move;
    vector<vector<int>> ans(0,vector<int>(0));
    rec(0,a,move,n,ans,0,target);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
