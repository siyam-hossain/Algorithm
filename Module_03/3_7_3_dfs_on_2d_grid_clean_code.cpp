#include<bits/stdc++.h>
using namespace std;

int r,c;
char grid[1005][1005];
bool vis[1005][1005];
vector< pair<int,int> > move_c = {{-1,0},{1,0},{0,-1},{0,1}};

bool valid(int i, int j)
{
    if(i<0 || i>=r || j<0 || j>=c)
        return false;
    return true;
}


void dfs(int si, int sj)
{
    cout<<si<<" "<<sj<<endl;
    vis[si][sj] = true;

    for (int i = 0; i < 4; i++)
    {
        int ci = si + move_c[i].first;

        int cj = sj + move_c[i].second;

        if(valid(ci,cj) == true && vis[ci][cj]==false)
        {
            dfs(ci,cj);
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
    cin>>si>>sj;
    memset(vis,false,sizeof(vis));
    dfs(si,sj);
    return 0;
}
/*
input:
3 4
....
....
....

1 2


*/