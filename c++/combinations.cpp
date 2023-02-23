#include<bits/stdc++.h>
using namespace std;
void rec1(int level,vector<int> &move,vector<int> &comb)
{
    for(auto i:move) cout<<i<<" ";
    cout<<endl;
    for(int i = level; i < comb.size();i++){
        move.push_back(comb[i]);
        rec1(i+1,move,comb);
        move.pop_back();
    }
}
void print(auto &vec){
    for(int i=0;i<vec.size();i++){
        for(int j=0;j<vec[i].size();j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
}
void rec2(int i,vector<int> &move,vector<int> &comb,vector<vector<int>> &ans){
    if(i==comb.size())
    {
        ans.push_back(move);
        return;
    }
    move.push_back(comb[i]);
    rec2(i+1,move,comb,ans);
    move.pop_back();
    rec2(i+1,move,comb,ans);
}
int main(){
    vector<int> comb={1,2,3};
    vector<int> move;
    vector<vector<int>> ans;
    rec2(0,move,comb,ans);
    sort(ans.begin(),ans.end());
    print(ans);
}