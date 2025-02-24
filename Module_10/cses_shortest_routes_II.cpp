#include<bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
    int n,e,ques;   
    cin>>n>>e>>ques;

    long long int adj_mat[n+5][n+5];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(i==j) adj_mat[i][j] = 0;
            else adj_mat[i][j] = LLONG_MAX;
        }
    }

    while (e--)
    {
        long long int a,b,c;
        cin>>a>>b>>c;


        adj_mat[a][b] = min(adj_mat[a][b],c);
        adj_mat[b][a] = min(adj_mat[b][a],c);
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if(adj_mat[i][k]!=LLONG_MAX && adj_mat[k][j]!=LLONG_MAX &&(adj_mat[i][j] > adj_mat[i][k]+adj_mat[k][j]) )
                adj_mat[i][j]  = adj_mat[i][k]+adj_mat[k][j];
            }
        }
    }
    
    while (ques--)
    {
        int sr,des;
        cin>>sr>>des;
        (adj_mat[sr][des]==LLONG_MAX) ? cout<<-1<<endl : cout<<adj_mat[sr][des]<<endl;
    }
    
    
    
    return 0;
}
/*
input: 
4 3 5
1 2 5
1 3 9
2 3 3
1 2
2 1
1 3
1 4
3 2


output:
5
5
8
-1
3

*/