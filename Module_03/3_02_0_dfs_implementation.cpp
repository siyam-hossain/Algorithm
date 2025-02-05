#include<bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool vis[1005];

void dfs(int src )
{
    //similar to binary depth wise traversal (recursion approach)

    //base case don't require

    //print kora
    cout<<src<<" ";
    vis[src] = true;
    for (auto child : adj_list[src])
    {
        //temporary work as base case
        if(vis[child] == false) //while not visited
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
    // memset(adj_list, 0, sizeof(adj_list));
    memset(vis, false, sizeof(vis)); 
    dfs(0);
       
    return 0;
}

/*
Input: 
7 7

0 2
2 4
0 1
1 5
1 3
0 3
3 6


*/