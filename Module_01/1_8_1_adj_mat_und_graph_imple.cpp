#include<bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
    int n,e;
    cin>>n>>e;

    //initialization
    int adj_mat[n][n];
    //set all index value to 0

    //long cut
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         adj_mat[i][j] = 0;
    //     }
    // }
    

    //short hand form
    // memset(varialbe name, value, sizeof(variable name));
    memset(adj_mat, 0, sizeof(adj_mat));

    //handle one edge case which is all principle element will be 1
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if(i==j)
                adj_mat[i][j] = 1;
    
    

    for (int i = 0; i < e; i++)
    {
        int a,b;
        cin>>a>>b;
        //insert this value into adjacency matrix
        //for undirected only
        adj_mat[a][b] = 1;
        adj_mat[b][a] = 1;
    }
    
    //printing section
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
           cout<<adj_mat[i][j]<<" ";
        }cout<<endl;
    }cout<<endl;
   
    return 0;
}
// input: 
    // 5 5 
    // 0 1
    // 0 2
    // 3 0
    // 1 3
    // 3 4