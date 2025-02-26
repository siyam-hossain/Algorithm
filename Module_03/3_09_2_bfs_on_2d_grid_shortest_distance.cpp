#include<bits/stdc++.h>
using namespace std;

int r,c;
char grid[1005][1005];
bool vis[1005][1005];
vector< pair<int,int> > move_c = {{-1,0},{1,0},{0,-1},{0,1}};
//track level
int level[1005][1005];


bool valid(int i, int j)
{
    if(i<0 || i>=r || j<0 || j>=c)
        return false;
    return true;
}

void bfs(int si, int sj)
{
    queue<pair<int,int>> q;
    q.push({si,sj});
    vis[si][sj] = true;

    level[si][sj]  = 0;

    while (!q.empty())
    {
        pair<int,int> par = q.front();
        q.pop();

        int par_i = par.first;
        int par_j = par.second;

        cout<<par_i<<" "<<par_j<<endl;

        for (int i = 0; i<4 ; i++)
        {
            int ci = par_i + move_c[i].first;
            int cj = par_j + move_c[i].second;
            if(valid(ci,cj) && !vis[ci][cj])
            {
                q.push({ci,cj});
                vis[ci][cj] = true; 
                level[ci][cj] = level[par_i][par_j] + 1;
            }
        }
        
    }
    
}


int main(int argc, char const *argv[])
{
    cin>>r>>c;   

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin>>grid[i][j];
        }
        
    }
    int si, sj;
    //destination index
    int di,dj;
    cin >> si >> sj >> di >>dj;
    memset(vis,false,sizeof(vis));
    memset(level, -1, sizeof(level));
    bfs(si,sj);
    cout<<"distance: "<<level[di][dj]<<endl;
    return 0;
}
/*
input:
3 4
....
....
....

1 2

destination index
2 0
*/