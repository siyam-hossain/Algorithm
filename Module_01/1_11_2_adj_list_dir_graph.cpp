#include<bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
    int n,e;
    cin>>n>>e;

    //array of vector
    vector<int> adj_list[n];

    while (e--)
    {
        int a,b;
        cin>>a>>b;

        //for directed graph (adj list)
        adj_list[a].push_back(b);
        //don't need it
        // adj_list[b].push_back(a);
    }
       
    //accessing array index
    for (int i = 0; i < n; i++)
    {
        cout<<i<<" -> ";
        //based on array index we print each index vector
        for (auto j : adj_list[i])
        {
            cout<<j<<" ";
        }cout<<endl;
    }
    
    
    return 0;
}