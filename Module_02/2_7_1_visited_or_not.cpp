#include<bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
bool vis_node[1005];

void BFS(int src)
{
    queue<int> q;
    q.push(src);
    vis_node[src] = true;


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

    //taking source and destination as input
    int src, dst;
    cin>>src>>dst;

    BFS(src);

    cout<<((vis_node[dst] == true) ? "YES\n" : "NO\n");
    return 0;
}

/*
Input: 
7 7
0 1
1 3
1 4
3 2
4 6
3 5
4 5

source and destination
0
4

Another input: 

7 5
0 1
1 3
3 2
4 6
3 5

0
4

*/