#include<bits/stdc++.h>
using namespace std;

vector<int> adj_list[105];
bool vis[105];
// change-0
int parent[105];
//change-2
bool cycle;

void dfs(int src)
{
    vis[src] = true;
    for (int child : adj_list[src])
    {
        if(vis[child] && parent[src] != child)
        {
            cycle = true;
        }
        if(!vis[child])
        {
            parent[child] = src;
            dfs(child);
            //change here
            
            // parent[child] = src;
            
            // to solve the conner case we have to rearrage the above statement over dfs recursion call
        }
    }
}


int main(int argc, char const *argv[])
{
    int n,e;
    cin>>n>>e;
    
    while (e--)
    {
        int a,b;
        cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    memset(vis,false,sizeof(vis));
    memset(parent,-1,sizeof(parent));

    //due to our source node is not fixed
    
    //change-3
    cycle = false;
    for (int i = 0; i < n; i++)
    {
        if(!vis[i])
            dfs(i);
    }
    
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<i<<" parent: "<<parent[i]<<endl;
    // }
    


    cout<<((cycle) ? "Detected Cycle\n": "No cycle\n");



    return 0;
}
/*
input:
5 4

1 0
2 3
3 4
4 2

//extra conner case
input:
2 1

1 0
output: cycle detected which is wrong


*/