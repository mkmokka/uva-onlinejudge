/*
12645 - Water Supply
*/

#include<bits/stdc++.h>
using namespace std;

vector<int>g[1010],top;
bool visited[1010];
int n,m;

void dfs1(int u)
{
    visited[u]=true;
    for(int i=0; i<g[u].size(); i++)
    {
        int v = g[u][i];
        if(!visited[v])
        {
            dfs1(v);
        }
    }
    top.push_back(u);
}
void dfs2(int u)
{
    visited[u]=true;
    for(int i=0; i<g[u].size(); i++)
    {
        int v = g[u][i];
        if(!visited[v])
        {
            dfs2(v);
        }
    }
}
int main()
{
    while(scanf("%d %d",&n,&m)==2)
    {
        for(int i=0; i<=n; i++)
        {
            g[i].clear();
        }
        memset(visited,false,sizeof(visited));
        top.clear();
        for(int i=0; i<m; i++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            if(b==0)
                continue;
            g[a].push_back(b);
        }
        for(int i=0; i<=n; i++)
        {
            if(!visited[i])
            {
                dfs1(i);
            }
        }
        reverse(top.begin(),top.end());
        memset(visited,false,sizeof(visited));
        int ans=0;
        for(int i=0; i<=n; i++)
        {
            int u = top[i];
            if(visited[u])
                continue;
            ans++;
            dfs2(u);
        }
        printf("%d\n",ans-1);
    }
    return 0;
}
/*
Sample Input
4 5
0 1
1 2
2 1
0 4
3 4
4 2
3 1
2 1

Sample Output
1
3
*/
