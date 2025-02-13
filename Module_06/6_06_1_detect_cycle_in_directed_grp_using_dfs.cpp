#include<bits/stdc++.h>
using namespace std;

vector<int> adj_list[105];
bool vis[105];
// change here
bool pathvis[105];
//change-2
bool cycle;

void dfs(int src)
{
    vis[src] = true;
    //change here
    pathvis[src] = true;

    for (int child : adj_list[src])
    {
        if(vis[child] && pathvis[child] == true)
        {
            cycle = true;
        }
        if(!vis[child])
        {

            dfs(child);
            
        }
    }
    //return
    //change here
    pathvis[src] = false;
}


int main(int argc, char const *argv[])
{
    int n,e;
    cin>>n>>e;
    
    while (e--)
    {
        int a,b;
        cin>>a>>b;
        // change here
        adj_list[a].push_back(b);
    }
    memset(vis,false,sizeof(vis));
    // change here
    memset(pathvis,false,sizeof(pathvis));

    //due to our source node is not fixed
    
    //change-3
    cycle = false;
    for (int i = 0; i < n; i++)
    {
        if(!vis[i])
            dfs(i);
    }
    

    cout<<((cycle) ? "Detected Cycle\n": "No cycle\n");



    return 0;
}
/*
input:
4 4

0 1
1 2
2 3
0 3

output: 
no cycle


input:
4 4

0 1
1 2
2 3
3 0

output:
cycle

*/