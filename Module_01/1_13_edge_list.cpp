#include<bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
    int n,e;
    cin>>n>>e;

    //we take input as pair
    vector<pair<int,int>> edge_list;
    while (n--)
    {
        int a,b;
        cin>>a>>b;
        //pushing value as pair
        edge_list.push_back({a,b});
    }
    for (auto i : edge_list)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }
    


    return 0;
}
/*
    input: 
    5 5 
    0 1
    0 2
    3 0
    1 3
    3 4
*/