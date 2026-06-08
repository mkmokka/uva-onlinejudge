/*
567 - Risk
*/

#include<bits/stdc++.h>
using namespace std;
#define MX 100
int level[MX];
int visited[100];
map<int,vector<int> >adj;

int bfs(int s, int n)
{
    memset(level,0,sizeof(level));
    memset(visited,0,sizeof(visited));

    queue<int>q;
    q.push(s);
    visited[s]=1;
    level[s]=0;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i=0; i<adj[u].size(); i++)
        {
            int v = adj[u][i];
            if(visited[v]==0)
            {
                visited[v]=1;
                level[v] = level[u]+1;
                q.push(v);
            }
        }
    }
    return level[n];

}


int main()
{
    int node,val,cas=0;;
    while(scanf("%d",&node)==1)
    {

        for(int i=0; i<node; i++)
        {
            cin>>val;
            adj[1].push_back(val);
            adj[val].push_back(1);
        }
        for(int i=2; i<=19; i++)
        {
            int now;
            scanf("%d",&now);
            for(int j=0; j<now; j++)
            {
                scanf("%d",&val);
                adj[i].push_back(val);
                adj[val].push_back(i);
            }
        }
        int qs,ans;
        scanf("%d",&qs);
        printf("Test Set #%d\n",++cas);
        for(int i=1; i<=qs; i++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            ans = bfs(a,b);
            printf("%2d to %2d: %d\n",a,b,ans);

        }
        printf("\n");
        adj.clear();
    }
    return 0;
}
/*
Sample Input
1 3
2 3 4
3 4 5 6
1 6
1 7
2 12 13
1 8
2 9 10
1 11
1 11
2 12 17
1 14
2 14 15
2 15 16
1 16
1 19
2 18 19
1 20
1 20
5
1 20
2 9
19 5
18 19
16 20
4 2 3 5 6
1 4
3 4 10 5
5 10 11 12 19 18
2 6 7
2 7 8
2 9 10
1 9
1 10
2 11 14
3 12 13 14
3 18 17 13
4 14 15 16 17
0
0
0
2 18 20
1 19
1 20
6
1 20
8 20
15 16
11 4
7 13
2 16

Sample Output
Test Set #1
1 to 20: 7
2 to 9: 5
19 to 5: 6
18 to 19: 2
16 to 20: 2

Test Set #2
1 to 20: 4
8 to 20: 5
15 to 16: 2
11 to 4: 1
7 to 13: 3
2 to 16: 4
*/

