#include<bits/stdc++.h>
using namespace std;
//global
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


void dfs(int si, int sj)
{
    // cout<<grid[si][sj]<<" ";
    
    vis[si][sj] = true;

//In grid any of a source has max 4 child there for loop run max 4
    for (int i = 0; i < 4; i++)
    {
        //child row position
        int ci = si + move_c[i].first;
        //child col position
        int cj = sj + move_c[i].second;

        // cout<<ci<<" "<<cj<<endl;
        if(vis[ci][cj]==false)
        {
            dfs(ci,cj);
        }
    }
      

    

}

int main(int argc, char const *argv[])
{
    int r,c;
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


// for (int i = 0; i < r; i++)
    // {
    //     for (int j = 0; j < c; j++)
    //     {
    //         cout<<grid[i][j];
    //     }cout<<endl;
    // }