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
    vis[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        int cr = si + move_c[i].first;
        int cl = sj + move_c[i].second;

        if(valid(cr,cl) && vis[cr][cl] == false && grid[cr][cl]=='.') //made mistake here
        {
            dfs(cr,cl);
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
    memset(vis,false,sizeof(vis));

    int num_aprt = 0;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if(grid[i][j] == '.')
            {
                if(!vis[i][j])
                {
                    num_aprt++;
                    dfs(i,j);
                }
            }
        }
        
    }
    
    cout<<num_aprt;
   
    
    return 0;
}
/*
input:
5 8
########
#..#...#
####.#.#
#..#...#
########

output: 
3
*/