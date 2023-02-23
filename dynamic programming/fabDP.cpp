#include<bits/stdc++.h>
using namespace std;
//applying memoizaion...

int fab(int indx,vector<int> &a){
    if(indx<=1) return indx;
    if(a[indx]!=-1) return a[indx];
    return a[indx] = fab(indx-1,a)+fab(indx-2,a);
}
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        vector<int>a(n+2,-1);
        cout<<fab(n,a);
    }
}