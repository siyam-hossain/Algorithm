#include<bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
    int n,e;
    cin>>n>>e;

    vector< pair<int,int> > adj_list[n];

    while (e--)
    {
        int a,b,c;
        cin>>a>>b>>c;

        adj_list[a].push_back({b,c});
        adj_list[b].push_back({a,c});
    }

    for (int i = 0; i < n; i++)
    {
        cout<<i<<" -> ";
        for (auto pir : adj_list[i])
        {
            cout<<pir.first<<" "<<pir.second<<", ";
        }
        cout<<endl;
    }
    
    
    return 0;
}