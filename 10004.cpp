/*
10004 - Bicoloring
*/
#include<bits/stdc++.h>
using namespace std;
int n,edge;
vector<int>mat[205];

bool isbipartite(int v, vector<bool>&vis,vector<int>&color)
{
    for(int u : mat[v])
    {
        if(vis[u]==false)
        {
            vis[u]=true;
            color[u]=!color[v];
            if(!isbipartite(u,vis,color))
                return false;
        }
        else if(color[u]==color[v])
            return false;
    }
    return true;

}

int main()
{
    /// freopen("input.txt", "r", stdin);
    /// freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(cin>>n)
    {
        if(n==0)
            break;
        cin>>edge;
        for(int i=0; i<n; i++)
        {
            mat[i].clear();
        }
        for(int i=0; i<edge; i++)
        {
            int x,y;
            cin>>x>>y;
            mat[x].push_back(y);
            mat[y].push_back(x);
        }
        vector<bool>vis(n+1,false);
        vector<int>color(n+1);
        vis[0]=true;
        color[0]=0;
        bool ans = isbipartite(0,vis,color);
        if(ans)
        {
            cout<<"BICOLORABLE."<<endl;
        }
        else
        {
            cout<<"NOT BICOLORABLE."<<endl;
        }
    }
    return 0;
}
/*
Sample Input
3
3
0 1
1 2
2 0
3
2
0 1
1 2
9
8
0 1
0 2
0 3
0 4
0 5
0 6
0 7
0 8
0

Sample Output
NOT BICOLORABLE.
BICOLORABLE.
BICOLORABLE.
*/
