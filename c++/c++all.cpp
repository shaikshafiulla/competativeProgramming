#include<bits/stdc++.h>
using namespace std;
void printmap(auto& map);
void print(auto &v){
    for(auto i:v){
        cout<<i<<" "<<endl;
    }
}

void vec(){
    /*
    begin
    end
    size
    empty
    front
    back
    push_back
    pop_baack
    insert
    clear
    */
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        //insertion
        v.emplace_back(a);
    }
    //itrating through the elements in vector
    for(auto &i:v){
        cout<<i<<" "<<endl;
    }
    //searchig
    auto it = find(v.begin(),v.end(),5);
    cout<<it-v.begin()<<endl;//to get the index position...

    //sorting 
    sort(v.begin(),v.end());
    for(auto &i:v){
        cout<<i<<" "<<endl;
    }
    //deletion...(last element)
    v.pop_back();
    print(v);
    //to define a 2d matrix 
    // vector<vector<int>> matrix(n,vector<int>(m,-1));

    // to remove the particular element or erase within particular range
    //to remove in a range(2 , 4)
    v.erase(v.begin()+2,v.begin()+4);
    print(v);
}
void mapping(){
    unordered_map<int,int> map;
    int a[5] = {5,2,7,9,2};
    for(int i=0;i<5;i++){
        //inserting ... in the form of pairs......
        map.insert({a[i],i});
    }
    //map traversal
    for(auto &i:map){
        cout<<i.first<<" "<<i.second<<endl;
    }
    //finding the particular key in map...
    auto itr = map.find(52);
    if(itr != map.end()){
        cout<<itr->first<<" "<<itr->second<<endl;
    }
    else{
        cout<<"element is not found"<<endl;
    }
    map.erase(2);
    printmap(map);
    
}
void printmap(auto &map){
    for(auto &i:map)
    {
        cout<<i.first<<" "<<i.second<<endl;

    }
}
int main()
{

    // vec();
    mapping();
    

}