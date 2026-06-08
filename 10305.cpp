/*
10305 - Ordering Tasks
*/

#include<bits/stdc++.h>
using namespace std;
#define NODE 101
int graph[NODE][NODE];
int n,m;

void dfs(int u,bool visited[],stack<int>&stk)
{
    visited[u]=true;
    for(int v=1; v<=n; v++)
    {
        if(graph[u][v])
        {
            if(!visited[v])
            {
                dfs(v,visited,stk);
            }
        }
    }
    stk.push(u);
}

void top_sort()
{
    stack<int>stk;
    bool visited[n];
    for(int i=1; i<=n; i++)
        visited[i]=false;
    for(int i=1; i<=n; i++)
    {
        if(!visited[i])
        {
            dfs(i,visited,stk);
        }
    }

    printf("%d",stk.top());
    stk.pop();
    while(!stk.empty())
    {
        printf(" %d",stk.top());
        stk.pop();
    }
    printf("\n");
}

int main()
{
    while(scanf("%d %d",&n,&m)==2)
    {
        if(n==0 && m==0)
            break;
        memset(graph,0,sizeof(graph));
        for(int i=1; i<=m; i++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            graph[a][b]=1;
        }
        top_sort();
    }
    return 0;
}
/*
Sample Input
5 4
1 2
2 3
1 3
1 5
0 0

Sample Output
1 4 2 5 3
*/
