/*
336 - A Node Too Far
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int node,x,y,n,p,cnt,cas=0;
    while(scanf("%d",&node)==1)
    {
        if(node==0)
            break;
        map<int,vector<int> >adj;
        for(int i=0; i<node; i++)
        {
            scanf("%d %d",&x,&y);
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        while(1)
        {
            scanf("%d %d",&n,&p);
            if(n==0 && p==0)
            {
                break;
            }
            queue<int>q;
            map<int, int>level;
            level[n]=0;
            q.push(n);
            int reach=1;
            while(!q.empty())
            {
                int y = q.front();
                q.pop();
                for(int i=0; i<adj[y].size(); i++)
                {
                    int v = adj[y][i];
                    if(level.count(v)==0)
                    {

                        level[v] = level[y]+1;

                        if(level[v]<=p)
                        {
                            ++reach;
                            q.push(v);
                        }

                    }
                }

            }
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",++cas,adj.size()-reach,n,p);

        }
    }
    return 0;
}
/*
Sample Input
16
10 15 15 20 20 25 10 30 30 47 47 50 25 45 45 65
15 35 35 55 20 40 50 55 35 40 55 60 40 60 60 65
35 2 35 3 0 0
14
1 2 2 7 1 3 3 4 3 5 5 10 5 11
4 6 7 6 7 8 7 9 8 9 8 6 6 11
1 1 1 2 3 2 3 3 0 0
0

Sample Output
Case 1: 5 nodes not reachable from node 35 with TTL = 2.
Case 2: 1 nodes not reachable from node 35 with TTL = 3.
Case 3: 8 nodes not reachable from node 1 with TTL = 1.
Case 4: 5 nodes not reachable from node 1 with TTL = 2.
Case 5: 3 nodes not reachable from node 3 with TTL = 2.
Case 6: 1 nodes not reachable from node 3 with TTL = 3.
*/

