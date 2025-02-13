#include<bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
    priority_queue< pair<int,int>, vector< pair<int,int> > , greater< pair<int,int> > > pq;

    pq.push({10,1});
    pq.push({5,2});

    cout<<pq.top().first<<" "<<pq.top().second;

    // priority queue prioritize only first member


    return 0;
}