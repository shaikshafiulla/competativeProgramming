#include<bits/stdc++.h>
using namespace std; 
void print(auto &vec)
{
    cout<<endl;
    for(auto i: vec)
    {
        cout<<i<<"\n"<<endl;
    }
}
void rec(int i,int j,auto &maze,auto &ans,string move,int n,auto &visited)
{
    //base condition
    if(i==n-1 and j==n-1)
    {
        ans.emplace_back(move);
        return;
    }
    //downward
    if(i+1<n and !visited[i+1][j] and maze[i+1][j]==1)
    {
        visited[i][j] = 1;
        rec(i+1,j,maze,ans,move+"d ",n,visited);
        visited[i][j] = 0;
    }
    //left
    if(j-1>=0 and !visited[i][j-1] and maze[i][j-1]==1)
    {
        visited[i][j] = 1;
        rec(i,j-1,maze,ans,move+"l ",n,visited);
        visited[i][j] = 0;
    }
    //right
    if(j+1<n and !visited[i][j+1] and maze[i][j+1]==1)
    {
        visited[i][j] = 1;
        rec(i,j+1,maze,ans,move+"r ",n,visited);
        visited[i][j] = 0;
    }
    //upward
    if(i-1>=0 and !visited[i-1][j] and maze[i-1][j]==1)
    {
        visited[i][j] = 1;
        rec(i-1,j,maze,ans,move+"u ",n,visited);
        visited[i][j] = 0;
    }
}
int main()
{
    vector<vector<int>> maze = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
    vector<vector<int>> visited(maze.size(),vector<int>(maze.size(),0));
    vector<string> ans;
    string move = "";
    rec(0,0,maze,ans,move,4,visited);
    print(ans);
}