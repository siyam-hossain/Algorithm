#include<bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
bool vis_node[1005];
int level[1005];
//tracking parent
int parent[1005];

void BFS(int src)
{
    queue<int> q;
    q.push(src);
    vis_node[src] = true;
    level[src] = 0;
    //src has not parent there for we assign it as -1; which is already set in main function there we don't need to assign it again
    // parent[src] = -1;


    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        for (auto child : adj_list[par])
        {
            if(vis_node[child] == false)
            {
                q.push(child);
                vis_node[child] = true;
                level[child] = level[par] + 1;

                //finding child node parent
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
        int a, b;
        cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    memset(vis_node,false,sizeof(vis_node));
    memset(level, -1, sizeof(level));
    //set parent
    memset(parent, -1, sizeof(parent));

    int src, dst;
    cin>>src>>dst;

    BFS(src);


    cout<<level[dst]<<endl;
    // cout<<parent[dst]<<endl;

    //printing path
    int node = dst;

    //for forword print
    vector<int> path;
    while (node != -1)
    {
        path.push_back(node);
        node = parent[node];
    }

    reverse(path.begin(),path.end());
    for (auto i : path)
    {
        cout<<i<<" ";
    }
    
    
    return 0;
}

/*
Input: 
8 8

0 1
1 3
3 2
1 4
3 5
2 5
4 6
5 7


0
7



*/