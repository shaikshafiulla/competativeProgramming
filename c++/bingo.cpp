#include<bits/stdc++.h>
using namespace std;
int c = 0;
bool safe(int i,int j,int n,auto &visited){
    if(i>=0 and i<n and j>=0 and j<n and visited[i][j]==0) return true;
    return false;
}

void rec(int i,int j,auto &vec,auto &visited,auto &ans,string move,int n)
{
    if(move.size()>1){
        for(char c:move){
            cout<<c<<" ";
        }
        cout<<endl;
    }
     
    //downward
    if(safe(i+1,j,n,visited) and vec[i+1][j] > vec[i][j]){
        visited[i][j] = 1;
        rec(i+1,j,vec,visited,ans,move+to_string(vec[i][j]),n);
        visited[i][j] = 0;
    }
    //upward
    if(safe(i-1,j,n,visited) and vec[i-1][j]>vec[i][j]){
        visited[i][j] = 1;
        rec(i-1,j,vec,visited,ans,move+to_string(vec[i][j]),n);
        visited[i][j] = 0;
    }
    //left
    if(safe(i,j-1,n,visited) and vec[i][j-1]>vec[i][j])
    {
        visited[i][j] = 1;
        rec(i,j-1,vec,visited,ans,move+to_string(vec[i][j]),n);
        visited[i][j] = 0;
    }
    //right
    if(safe(i,j+1,n,visited) and vec[i][j+1]>vec[i][j])
    {
        visited[i][j] = 1;
        rec(i,j+1,vec,visited,ans,move+to_string(vec[i][j]),n);
        visited[i][j] = 0;
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> vec(n,vector<int> (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int x;
            cin>>x;
            vec[i][j] = x;
        }
    }
    vector<vector<int>> visited(n,vector<int> (m,0));
    vector<vector<string>> ans;
    string move = "";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            rec(i,j,vec,visited,ans,move,n);
        }
    }
}