#include<bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
    int n,e;
    cin>>n>>e;
    int adj_mat[n][n];
    
    //make all element infinite
    //we don't use memset due to it doesnot work properly with integer max
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i==j) adj_mat[i][j] = 0;
            else adj_mat[i][j] = INT_MAX;
        }
    }

    

    while (e--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        
        adj_mat[a][b] = c;
        // adj_mat[b][a] = c;//for undirected grap
        
    }

    // floyd warshall
    // O(N^3)
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // cout<<i<<" "<<k<<" "<<j<<endl;
                if( adj_mat[i][k]!=INT_MAX && adj_mat[k][j]!=INT_MAX && (adj_mat[i][j] > (adj_mat[i][k] + adj_mat[k][j]) ) )
                adj_mat[i][j] = adj_mat[i][k] + adj_mat[k][j];

            }
            
        }
    }
    
    
    

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(adj_mat[i][j]==INT_MAX) cout<<"INF"<<"\t\t";
            else cout<<adj_mat[i][j]<<"\t\t";
        }cout<<endl;
    }
    
    return 0;
}
/*
input: 
4 5
0 1 3
0 2 6
1 2 2
1 3 5
2 3 4

output:
0 3 5 8 
INF 0 2 5 
INF INF 0 4 
INF INF INF 0 

*/