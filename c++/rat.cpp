#include<bits/stdc++.h>
using namespace std;
int issafe(int i,int j,int n,int m,auto &vec){
    if(i>=0 and i<n and j>=0 and j<m and vec[i][j]==1) return true;
    return false;
}
void recursion(int i,int j,int n,int m,auto &vec,auto &visited,string move)
{
    if(i==n-1 and j==n-1)
    {
        for(auto i: move) cout<<i<<" ";
        cout<<endl;
        return;
    }
    //downward....
    if(issafe(i+1,j,n,m,vec) and visited[i+1][j]==-1){
        visited[i][j]=1;
        //move.push_back({i,j});
        recursion(i+1,j,n,m,vec,visited,move+"d");
        //move.pop_back();
        visited[i][j]=-1;
    }
    //left
    if(issafe(i,j-1,n,m,vec) and visited[i][j-1]==-1){
        visited[i][j]=1;
        //move.push_back({i,j});
        recursion(i,j-1,n,m,vec,visited,move+"l");
        //move.pop_back();
        visited[i][j]=-1;
    }
    //right
    if(issafe(i,j+1,n,m,vec) and visited[i][j+1]==-1){
        visited[i][j]=1;
        //move.push_back({i,j});
        recursion(i,j+1,n,m,vec,visited,move+"r");
        //move.pop_back();
        visited[i][j]=-1;
    }
    //upward
    if(issafe(i-1,j,n,m,vec) and visited[i-1][j]==-1){
        visited[i][j]=1;
        //move.push_back({i,j});
        recursion(i-1,j,n,m,vec,visited,move+"u");
        //move.pop_back();
        visited[i][j]=-1;
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int> > vec(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>vec[i][j];
        }
    }
    string move="";
    vector<vector<int>> visited(n,vector<int>(m,-1));
    recursion(0,0,n,m,vec,visited,move);
}