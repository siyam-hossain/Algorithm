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

int dfs(int si, int sj)
{
    vis[si][sj] = true;
    int cnt_room = 1; //i made mistake here

    for (int i = 0; i < 4; i++)
    {
        int cr = si + move_c[i].first;
        int cl = sj + move_c[i].second;
        
        if(valid(cr,cl) && vis[cr][cl] == false && grid[cr][cl]=='.') 
        {   
            cnt_room += dfs(cr,cl);
        }
    }
    return cnt_room;
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
    vector<int> num_room;

    memset(vis,false,sizeof(vis));
    

    
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if(grid[i][j] == '.')
            {
                if(!vis[i][j])
                {
                   int cnt = dfs(i,j);
                   num_room.push_back(cnt);
                }
            }
        }
    }

    if(!num_room.empty()) 
    {
        sort(num_room.begin(),num_room.end());
        for (auto room : num_room)
            cout<<room<<" ";
        cout<<endl;
    }
    else
    {
        cout<<"0"<<endl;
    }

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
2 2 8
*/