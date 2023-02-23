#include<bits/stdc++.h>
using namespace std;
bool issafe(int x,int y,int n,auto &visited){
    if(x>=0 and x<n and y>=0 and y<n and visited[x][y]==-1) return true;
    return false;
}
void rec(auto &caze,int x,int y,int dx,int dy,int n,auto &visited,auto &move){
    //cout<<"*";
    if(x==dx and y==dy){
        move.emplace_back(x,y);
        for(auto i: move)
        {
            cout<<i.first<<" "<<i.second;
            cout<<endl;
        }
        cout<<endl;
        return;
    }
    //upward
    if(issafe(x-1,y,n,visited)){
        visited[x][y] = 1;
        move.emplace_back(x,y);
        rec(caze,x-1,y,dx,dy,n,visited,move);
        move.pop_back();
        visited[x][y] = -1;
    }
    //right
    if(issafe(x,y+1,n,visited)){
        visited[x][y] = 1;
        move.emplace_back(x,y);
        rec(caze,x,y+1,dx,dy,n,visited,move);
        move.pop_back();
        visited[x][y] = -1;
    }

}
int main(){
    int n,x,y,dx,dy;
    cin>>n>>x>>y>>dx>>dy;
    vector<vector<int>> caze(n,vector<int>(n));
    vector<pair<int,int>> move;
    vector<vector<int>> visited(n,vector<int>(n,-1));
    cout<<endl;
    rec(caze,x,y,dx,dy,n,visited,move);
}