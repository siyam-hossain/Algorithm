#include<bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool vis[1005];

void dfs(int src )
{
    // cout<<src<<" ";
    vis[src] = true;
    for (auto child : adj_list[src])
    {
        if(vis[child] == false) 
        {
            dfs(child);
        }
    } 
}

int main(int argc, char const *argv[])
{
    int n, e;
    cin>>n>>e;

    while (e--)
    {
        int a,b;
        cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    
    int num_comp = 0;
    for (int i = 0; i < n; i++)
    {
        if(vis[i]==false)
        {
            dfs(i);
            // cout<<endl;
            num_comp++;
        }
    }
    cout<<"Nuber of component: "<<num_comp<<endl;
    
    return 0;
}

/*
Input: 
8 6

1 2
0 5
2 3
6 7
4 5
1 3

*/