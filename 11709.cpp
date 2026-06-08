/*
11709 - Trust groups
*/
#include<bits/stdc++.h>
using namespace std;
#define MX 1005
vector<int>g[MX];
vector<int>rg[MX];
vector<int>order;
vector<bool>used(MX);
int node,edge;
void clearerr()
{
    for(int i=0; i<=node; i++)
    {
        g[i].clear();
        rg[i].clear();
        used[i]=false;
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
    used[u]=false;
    for(int i=0; i<rg[u].size(); i++)
    {
        if(used[rg[u][i]])
        {
            dfs2(rg[u][i]);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    while(scanf("%d %d",&node,&edge)==2)
    {
        if(node==0 && edge==0)
            break;
        getchar();
        clearerr();
        map<string,int>mp;
        char name1[1005];
        char name2[1005];
        for(int i=1; i<=node; i++)
        {
            gets(name1);
            mp[name1]=i;
        }
        for(int i=1; i<=edge; i++)
        {
            gets(name1);
            gets(name2);
            g[mp[name1]].push_back(mp[name2]);
            rg[mp[name2]].push_back(mp[name1]);
        }
        for(int i=1; i<=node; i++)
        {
            if(!used[i])
            {
                dfs1(i);
            }
        }
        int ans=0;
        for(int i=0; i<node; i++)
        {
            int v = order[node-1-i];
            if(used[v])
            {
                ans++;
                dfs2(v);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
/*
Sample Input
3 2
McBride, John
Smith, Peter
Brown, Anna
Brown, Anna
Smith, Peter
Smith, Peter
Brown, Anna
3 2
McBride, John
Smith, Peter
Brown, Anna
Brown, Anna
Smith, Peter
McBride, John
Smith, Peter
0 0

Sample Output
2
3
*/
