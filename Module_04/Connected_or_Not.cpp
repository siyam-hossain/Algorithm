#include<bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
    int n,e;
    cin>>n>>e;

    int adj_mat[n][n];

    memset(adj_mat, 0, sizeof(adj_mat));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if(i==j)
                adj_mat[i][j] = 1;
    
    
    while (e--)
    {
        int a,b;
        cin>>a>>b;
        adj_mat[a][b] = 1;
    }

    int que;
    cin>>que;

    while (que--)
    {
        int a,b;
        cin>>a>>b;

        if(a==b) 
        {
            cout<<"YES\n";
            continue;
        }
        cout<<((adj_mat[a][b]==1) ? "YES\n" : "NO\n");  
    }
       
    return 0;
}
