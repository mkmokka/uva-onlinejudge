/*
12376 - As Long as I Learn, I Live
*/

#include<bits/stdc++.h>
using namespace std;
int n,m,ss[101],ans,endd;
vector<int>graph[101];
bool vis[101];

void dfs(int u)
{
    vis[u]=true;
    int mx=0,temp=-1;
    for(int i=0; i<graph[u].size(); i++)
    {
        int v = graph[u][i];
        if(!vis[v])
        {
            if(ss[v]>mx)
            {
                mx = ss[v];
                temp=v;
            }
        }
    }
    if(temp!=(-1))
    {
        endd=temp;
        ans+=mx;
        dfs(endd);
    }
    return;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t,tc=0;
    scanf("%d\n",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        for(int i=0; i<n; i++)
        {
            scanf("%d",&ss[i]);
            graph[i].clear();
        }
        for(int i=0; i<m; i++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            graph[x].push_back(y);
        }
        memset(vis,false,sizeof(vis));
        dfs(0);
        printf("Case %d: %d %d\n",++tc,ans,endd);
        ans=0,endd=0;
    }
    return 0;
}
/*
Sample Input
1

6 6
0 8 9 2 7 5
5 4
5 3
1 5
0 1
0 2
2 1

Sample Output
Case 1: 29 4
*/
