/*
10765 - Doves and bombs
*/

#include<bits/stdc++.h>
using namespace std;
#define UNVISITED 0
#define MX 10010
int dfs_num[MX];
int dfs_low[MX];
int dfs_parent[MX];
int articulation_vertex[MX];
vector<vector<int>>AdjList;
int root,counter,childnodes,n,m;


void articulationPointAndBridge(int u)
{
    dfs_num[u]=dfs_low[u]=++counter;
    for(int i=0; i<(int)AdjList[u].size(); i++)
    {
        int v = AdjList[u][i];
        if(dfs_num[v]==UNVISITED)
        {
            dfs_parent[v]=u;
            if(u==root)
                childnodes++;
            articulationPointAndBridge(v);
            if(dfs_low[v]>=dfs_num[u])
                articulation_vertex[u]++;

            dfs_low[u]=min(dfs_low[u],dfs_low[v]);
        }
        else if(v!=dfs_parent[u])
        {
            dfs_low[u]=min(dfs_low[u],dfs_num[v]);
        }
    }
}

int main()
{
    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(cin>>n>>m)
    {
        if(n==0 && m==0)
            break;
        AdjList.assign(n,vector<int>());
        int x,y;
        while(cin>>x>>y)
        {
            if(x==(-1) && y==(-1))
                break;
            AdjList[x].push_back(y);
            AdjList[y].push_back(x);
        }
        int cc=0;
        for(int i=0; i<n; i++)
        {
            dfs_num[i]=dfs_low[i]=0;
            articulation_vertex[i]=0;
            dfs_parent[i]=i;
        }
        for(int i=0; i<n; i++)
        {
            if(dfs_num[i]==UNVISITED)
            {
                counter=0;
                cc++;
                root =i;
                childnodes=0;
                articulationPointAndBridge(i);
                articulation_vertex[i]=childnodes-1;
            }
        }
        multimap<int,int,greater<int>>bombs;
        for(int i=0; i<n; i++)
        {
            bombs.insert({cc+articulation_vertex[i],i});
        }
        int j=0;
        for(multimap<int,int>::iterator it =bombs.begin(); it!=bombs.end() && j<m ; ++it,++j)
        {
            cout<<it->second<<" "<<it->first<<endl;
        }
        cout<<endl;
    }
    return 0;
}

/*
Sample Input
8 4
0 4
1 2
2 3
2 4
3 5
3 6
3 7
6 7
-1 -1
0 0

Sample Output
2 3
3 3
4 2
0 1
*/
