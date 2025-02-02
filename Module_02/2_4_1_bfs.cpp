#include<bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
bool vis_node[1005];

void BFS(int src)
{
    queue<int> q;
    q.push(src);
    //true visited node while pushing
    vis_node[src] = true;


    while (!q.empty())
    {
        //ber kore ana
        int par = q.front();
        q.pop();

        //oi node ke niye kaj
        cout<<par<<" ";

        //children gulo push kora ---> from adj list

        for (auto child : adj_list[par])
        {
            //don't push value while the node is already visited
            if(vis_node[child] == false)
            {
                q.push(child);
                //true visited node while pushing
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
    //before call BFS
    memset(vis_node,false,sizeof(vis_node));

    //now call BFS
    BFS(0);


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

*/