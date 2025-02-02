#include<bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
bool vis_node[1005];

void BFS(int src)
{
    queue<int> q;
    q.push(src);
    vis_node[src] = true;


    while (!q.empty()) //O(N)
    {
        int par = q.front();
        q.pop();
        cout<<par<<" ";
        for (auto child : adj_list[par]) //O(E)
        {
            //loop depends on this condition
            //therefore this while and for is not nested loop
            if(vis_node[child] == false)
            {
                q.push(child);
                vis_node[child] = true;
            }
        }
    }
    //Over all complexity: O(N + E) or O(V + E);
    
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
    BFS(0);
    return 0;
}

