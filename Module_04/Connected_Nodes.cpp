#include<bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
    int n,e;
    cin>>n>>e;

    vector<int> adj_list[n];
    int arr_node[1005];
    memset(arr_node,0,sizeof(arr_node));

    while (e--)
    {
        int a,b;
        cin>>a>>b;

        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
        arr_node[a] = a;
        arr_node[b] = b;
    }

    int que;
    cin>>que;

    for (int i = 0; i < que; i++)
    {
        int vertex;
        cin>>vertex;
        if(arr_node[vertex]==vertex && !adj_list[i].empty())
        {
            sort(adj_list[vertex].begin(),adj_list[vertex].end(),greater<int>());

            for (auto j : adj_list[vertex])
            {
                cout<<j<<" ";
            }cout<<endl;

        }
        else
        {
            cout<<"-1\n";
            continue;
        }
        
    }

    // for (int i = 0; i < 10; i++)
    // {
    //     cout<<arr_node[i]<<" ";
    // }
    
    
    return 0;
}