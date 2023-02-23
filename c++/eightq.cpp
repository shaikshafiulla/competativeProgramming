 #include<bits/stdc++.h>
 using namespace std;
 int queen[20];
 void print(auto &vec){
    for(int i=0;i<vec.size();i++)
    {
        for(int j=0;j<vec[i].size();j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
 }
 bool issafe(int row,int col){
    for(int i=0;i<row;i++){
        int prow = i;
        int pcol = queen[i];
        if(pcol==col or abs(prow-row)==abs(pcol-col)) return false;
    }
    return true;
 }
 void rec(int x,int y,vector<vector<int>> &board,int *queen,vector<int> &move,int n,vector<vector<int>> &visited,auto &ans)
 {
    if(x==board.size()){
        ans.emplace_back(move);
        // for(auto i: move){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        return;
    }
    for(int col=0;col<board.size();col++){
        if(issafe(x,col)){
            queen[x] = col;
            move.push_back(col);
            rec(x+1,col,board,queen,move,n,visited,ans);
            move.pop_back();
            queen[x] = 0;
        }

    }
 }
 int main(){
    int n;
    cin>>n;
    vector<int> move;
    vector<vector<int>> board(n,vector<int>(n,0));
    vector<vector<int>> visited(n,vector<int>(n,-1));
    vector<vector<int>> ans;
    rec(0,0,board,queen,move,n,visited,ans);
    print(ans);
 }