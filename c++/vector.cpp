/*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void printfunction(vector<string> &v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }
}
int main(){
    vector<string> v;
    v.push_back("shafiulla");
    v.push_back("shaik");
    // cout<<v.size()<<endl;
    // printfunction(v);
    // v.pop_back();
    // printfunction(v);
    cout<<v.at(v.begin())<<endl;
}
*/

/*
//vector of pairs....
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<pair<int,string>>v ;
    int n;
    cin>>n;
    int no;
    string name;
    for(auto i=0;i<n;i++){
        cout<<"enter the value"<<endl;
        cin>>no;
        cout<<"enter the string"<<endl;
        cin>>name;
        v.push_back(make_pair(no,name)); //v.push_back({no,name});
    }
    for(auto it = v.begin();it!=v.end();it++){
        cout<<it->first<<" "<<(*it).second<<endl;
    }
}
*/
//vector of vector........
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<int>> ve;
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        vector<int> temp;
        int n;
        cin>>n;
        for(int j=0;j<n;j++){
            int c;
            cin>>c;
            temp.push_back(c);
        }
        ve.push_back(temp);
    }
    // cout<<ve[0][0]<<endl;
    for(int i=0;i<ve.size();i++){
        for(int j=0;j<ve[i].size();j++){
            cout<<ve[i][j]<<" ";
        }
        cout<<endl;
    }
}
// array of vectors is similar to that of two dimensional arrays 
/*

     IN SLT CONTAINERS DURING FUNCTION CALLS THEY ARE PASSED BY VALUE BUT NOT REFERENCE
     AND THIS IS SIMILAR TO FOR EACH LOOP WHILE DEALING WITH SLT..

     WE CANT USECOMPLEX COMPONENTS IN UNORDERMAP AND UNORDERSET
     
  v.size() -----O(1)
  vector<int>v1 = v     here only copy will be done...  takes O(n) complexity


  different ways to initialize the vector

  1 way assigining the array 
    int arr[3] = {1,2,3};
    vector<int> v(arr,arr+3);  if vector   vector<int>v1(v.begin(),v.end());
 2 way  default initialization
  vector<int> v(n,0);
*/
