#include<iostream>
using namespace std;
int main()
{
    //initialize the pair...
    pair<int,string > p,p1;
    p.first = 23;
    p.second = "shafiulla";
    cout<<p.first<<" "<<p.second<<endl;
    p1 = {2,"rohith"};
    cout<<p1.first<<" "<<p1.second;
    pair<int,string> p3;
    p3 = make_pair(73,"venu");
    cout<<p3.first<<" "<<p3.second<<endl;

    pair of arrays...
    int n;
    cin>>n;
    pair<int,int> parray[n];
    for(int i=0;i<n;i++){
        cin>>parray[i].first>>parray[i].second;
    }
    for(auto pair:parray){
        cout<<pair.first<<" "<<pair.second<<endl;
    }




}