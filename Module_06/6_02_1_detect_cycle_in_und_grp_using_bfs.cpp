#include<bits/stdc++.h>
using namespace std;

vector<int> adj_list[105];
bool vis[105];
// change-0
int parent[105];
//change-2
bool cycle;

void bfs(int src)
{
    queue<int>q;
    q.push(src);
    vis[src] = true;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        // cout<<par<<" ";
        for (auto child : adj_list[par])
        {
            // change-4
            if(vis[child] && parent[par] != child)
            {
                cycle = true;
            }
            if(!vis[child])
            {
                q.push(child);
                vis[child] = true;

                //change-1
                parent[child] = par;
            }
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
            bfs(i);
    }
    
    cout<<((cycle) ? "Detected Cycle\n": "No cycle\n");



    return 0;
}
/*
input:
6 4

0 1
1 2
2 3
3 0
4 5

*/