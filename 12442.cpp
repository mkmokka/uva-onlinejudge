/*
12442 - Forwarding Emails
*/

#include<bits/stdc++.h>
using namespace std;
int n,m,endd,cnt;
vector<int>graph;
vector<int>sum;
vector<bool>vis;

int dfs(int u)
{
    vis[u]=true;
    int total=0;
    if(graph[u]!=(-1)&& !vis[graph[u]])
        total+=1+dfs(graph[u]);
    vis[u]=false;
    return sum[u]=total;
}

int main()
{
    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    int t,tc=0;
    scanf("%d\n",&t);
    while(t--)
    {
        scanf("%d",&n);
        graph.assign(n,-1);
        sum.assign(n,-1);
        vis.assign(n,false);
        for(int i=0; i<n; i++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            x--;
            y--;
            graph[x]=y;
        }
        int ans=0,idx=0;
        for(int i=0; i<n; i++)
        {
            cnt=0;
            if(sum[i]==(-1))
            {
                dfs(i);
            }
            if(sum[i]>ans){
                ans = sum[i];
                idx=i;
            }
        }
        printf("Case %d: %d\n",++tc,idx+1);
    }
    return 0;
}
/*
Sample Output
3
3
1 2
2 3
3 1
4
1 2
2 1
4 3
3 2
5
1 2
2 1
5 3
3 4
4 5

Sample Output
Case 1: 1
Case 2: 4
Case 3: 3
*/

