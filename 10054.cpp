/*
10054 - The Necklace
*/
#include<bits/stdc++.h>
using namespace std;
const int MX = 55;
int parent[MX];
int degree[MX];
int graph[MX][MX];
int n;
///initialize
void init()
{
    memset(degree,0,sizeof(degree));
    memset(graph,0,sizeof(graph));
    for(int i=0; i<MX; i++)
    {
        parent[i]=i;
    }
}
///find parent
int find_parent(int x)
{
    if(x!=parent[x])
    {
        parent[x] = find_parent(parent[x]);
    }
    return parent[x];
}
///checking whether all degree's are even
/// and the graph is connected
bool isok()
{
    int root = -1;
    for(int i=0; i<MX ; i++)
    {
        if(degree[i]&1)
            return false;
        if(degree[i])
        {
            if(root == -1)
                root = find_parent(i);
            else
            {
                if(root != find_parent(i))
                    return false;
            }
        }
    }
    return true;
}
///printing  euler path
void dfs(int cur)
{
    for(int i=1; i<MX; i++)
    {
        if(graph[cur][i])
        {
            graph[cur][i]--;
            graph[i][cur]--;
            dfs(i);
            printf("%d %d\n",i,cur);
        }

    }
}

int main()
{
    int cas=1,t,x,y,start;
    bool isfirst = true;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        init();
        for(int i=0; i<n; i++)
        {
            scanf("%d %d",&x,&y);
            start = x;
            graph[x][y]++;
            graph[y][x]++;
            degree[x]++;
            degree[y]++;
            parent[find_parent(x)]=find_parent(y);
        }
        if(isfirst)
            isfirst=false;
        else
        {
            printf("\n");
        }
        printf("Case #%d\n",cas++);
        if(!isok())
        {
            printf("some beads may be lost\n");
        }
        else
        {
            dfs(start);
        }
    }
    return 0;
}
/*
Sample Input
2
5
1 2
2 3
3 4
4 5
5 6
5
2 1
2 2
3 4
3 1
2 4

Sample Output
Case #1
some beads may be lost

Case #2
2 1
1 3
3 4
4 2
2 2
*/
