/*
#include<bits/stdc++.h>
using namespace std;

priority_queue<int> priority(auto &vec)
{
    priority_queue<int> pq;
    for(int &i: vec)
    {
        pq.push(i);

    }
    return pq;
}
void print(auto &vec)
{
    for(int i=0;i<vec.size();i++)
    {
        for(int j=0;j<vec[i].size();j++)
        {
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int n,m;
    n = 5;
    m = 3;
    // vector<vector<int>> matrix(n,vector<int>(m,-1));
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<m;j++){
    //         matrix[i][j] = rand()%10;
    //     }
    // }
    // // vector<int> matrix(n,2);

    // print(matrix);
    // cout<<endl;
    
    // sort(matrix.begin(),matrix.end());
    // print(matrix);

//     vector<int> vec = {5,4,7,1,2,9,8,4,3,2};
//     auto ans = priority(vec);
//    while(ans.size()>0) 
//     {
//         cout<<ans.top()<<" ";
//         ans.pop();
//     }
    int arr[] = {5,4,7,1,2,9,8,4,3,2};
    sort(arr,arr+10);
    for(auto &i:arr)
    {
        cout<<arr[i]<<",";
    }

    
    return 0;

}
*/

#include<bits/stdc++.h>
using namespace std;

bool cmpr(pair<int,int> &p1,pair<int,int> &p2)
{
    if(p1.first<p2.first) return true;
    else if (p1.first>p2.first) return false;
    else return p1.second>p2.second;
}

int main()
{
    int arrr1[] = {1,3,2,3,1};
    int arrr2[] = {3,5,6,9,2};
    
    pair<int,int> p[5];
    for(int i=0;i<5;i++)
    {
        p[i] = make_pair(arrr1[i],arrr2[i]);
    }
    for(int i=0;i<5;i++)
    {
        cout<<p[i].first<<" "<<p[i].second<<endl;
    }
    cout<<"\n"<<endl;
    sort(p,p+5,cmpr);
    for(int i=0;i<5;i++)
    {
        cout<<p[i].first<<" "<<p[i].second<<endl;
    }
}