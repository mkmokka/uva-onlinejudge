/*
11770 - Lighting Away
*/

#include<bits/stdc++.h>
using namespace std;
#define MX 10000
vector<int>g[MX];
vector<int>order;
vector<bool>used(MX);
vector<bool>used2(MX);
int node,edge;
void clearerr()
{
    for(int i=0; i<=node; i++)
    {
        g[i].clear();
        used[i]=false;
        used2[i]=false;
    }
    order.clear();
}
void dfs1(int u)
{
    used[u]=true;
    for(int i=0; i<g[u].size(); i++)
    {
        if(!used[g[u][i]])
        {
            dfs1(g[u][i]);
        }
    }
    order.push_back(u);
}

void dfs2(int u)
{
    used2[u]=true;
    for(int i=0; i<g[u].size(); i++)
    {
        if(!used2[g[u][i]])
        {
            dfs2(g[u][i]);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ///freopen("input.txt", "r", stdin);
    /// freopen("output.txt", "w", stdout);
    int t,tc=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&node,&edge);
        clearerr();
        for(int i=1; i<=edge; i++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            g[x].push_back(y);
        }
        int ans=0;
        for(int i=1; i<=node; i++)
        {
            if(!used[i])
            {
                dfs1(i);
            }
        }
        for(int i=0; i<node; i++)
        {
            int v = order[node-1-i];
            if(!used2[v])
            {
                ans++;
                dfs2(v);
            }
        }
        printf("Case %d: %d\n",++tc,ans);
    }
    return 0;
}
/*
Sample Input
2
5 4
1 2
1 3
3 4
5 3

4 4
1 2
1 3
4 2
4 3

Sample Output
Case 1: 2
Case 2: 2
*/
