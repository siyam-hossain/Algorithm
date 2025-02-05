#include<bits/stdc++.h>
using namespace std;
//global

int r,c;

char grid[1005][1005];
bool vis[1005][1005];

vector< pair<int,int> > move_c = {{-1,0},{1,0},{0,-1},{0,1}};

/*
    child movement
    -1   0
     1   0
     0  -1
     0   1
*/
//check child index valid or not
bool valid(int i, int j)
{
    //row = 3: valid when (0,1,2)
    if(i<0 || i>=r || j<0 || j>=c)
        return false;
    return true;
}


void dfs(int si, int sj)
{
    cout<<si<<" "<<sj<<endl;
    
    vis[si][sj] = true;

//In grid any of a source has max 4 child there for loop run max 4
    for (int i = 0; i < 4; i++)
    {
        //child row position
        int ci = si + move_c[i].first;
        //child col position
        int cj = sj + move_c[i].second;

        // cout<<ci<<" "<<cj<<endl;
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