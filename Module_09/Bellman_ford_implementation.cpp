#include<bits/stdc++.h>
using namespace std;

class Edge
{   
    public:
    int a,b,c;
    Edge(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};
int dis[105];


int main(int argc, char const *argv[])
{
    int n,e;
    cin>>n>>e;


    vector<Edge> edg_list;
    while (e--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        edg_list.push_back(Edge(a,b,c));
        // edg_list.push_back(Edge(b,a,c));//undirected graph


    }
    for (int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
    }
    dis[0] = 0;
    
    for (int i = 0; i < n-1; i++)
    {
        for (auto edg : edg_list)
        {
            int a,b,c;
            a = edg.a;
            b = edg.b;
            c = edg.c;
            if(dis[a]!=INT_MAX && (dis[a]+c < dis[b]))
            {
                dis[b] = dis[a] + c;
            }
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        cout<<i<<" -> "<<dis[i]<<endl;
    }
    
    
    
    return 0;
}