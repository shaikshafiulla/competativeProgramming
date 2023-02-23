/*
given 2 arrays of equal length where indexes are linked...
you have to sort array1 in ascending order
if the elements in the array1 are equal then sort by value of array2 in descending order

input-->
     5
     4 5 5 1 7
     2 3 6 7 8
output-->
     1 4 5 5 7
     7 2 6 3 8

    
*/
#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> p1,pair<int,int> p2)
{
    if (p1.first!=p2.first)
    return p1.first<p2.first;
    else
    return p1.second>p2.second;
}
int main(){
    int n;
    cin>>n;
    vector<pair<int,int> > v;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    cout<<"before sorting : "<<endl;
    for(auto i=v.begin();i!=v.end();++i){
        cout<<i->first<<" "<<i->second<<endl;
    }
    sort(v.begin(),v.end(),compare);
    cout<<"after sorting : "<<endl;
    for(auto it :v){
        cout<<it.first<<" "<<it.second<<endl;
    }
}