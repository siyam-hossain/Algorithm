#include<bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
bool vis_node[1005];
//traking level
int level[1005];

void BFS(int src)
{
    queue<int> q;
    q.push(src);
    vis_node[src] = true;
    //source node level is 0
    //assigning it 
    level[src] = 0;


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

                //children level = parent level + 1
                level[child] = level[par] + 1;
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
    //same we have to initialize level while no node present which is -1
    memset(level, -1, sizeof(level));

    //taking source and destination as input
    int src, dst;
    cin>>src>>dst;

    BFS(src);

    //now printing destination node level
    cout<<level[dst]<<endl;
    return 0;
}

/*
Input: 
7 8

0 1
1 3
3 2
1 4
3 5
2 5
5 6
4 6


0
4


*/