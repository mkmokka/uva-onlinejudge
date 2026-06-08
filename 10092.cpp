/*
10092 - The Problem with the Problem Setter
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1105;


int graph[maxn][maxn];
int n,m,tt,sum;

bool bfs(int s,int t,int parent[])
{
    bool visit[tt+1]= {false};
    parent[s]=-1;
    queue<int>q;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int v=0; v<=tt; v++)
        {
            if(visit[v]==false && graph[u][v]>0)
            {
                if(v==t)
                {
                    parent[v]=u;
                    return true;
                }
                q.push(v);
                visit[v]=true;
                parent[v]=u;
            }
        }
    }
    return false;
}

int ford_fulkerson(int s,int t)
{
    int u,v;
    int parent[tt+1];
    int max_flow=0;
    while(bfs(s,t,parent))
    {
        int path_flow=INT_MAX;
        for(v=t; v!=s; v=parent[v])
        {
            u = parent[v];
            path_flow=min(path_flow,graph[u][v]);
        }
        for(v=t; v!=s; v=parent[v])
        {
            u = parent[v];
            graph[u][v]-=path_flow;
            graph[v][u]+=path_flow;
        }
        max_flow+=path_flow;
    }
    return max_flow;
}


int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(cin>>n>>m && !(n==0 && m==0))
    {
        tt = n+m+1;
        for(int i=0; i<=tt; i++)
        {
            for(int j=0; j<=tt; j++)
            {
                graph[i][j]=0;
            }
        }
        sum=0;
        for(int i=1; i<=n; i++)
        {
            cin>>graph[0][i];
            sum+=(graph[0][i]);
        }
        for(int i=1; i<=m; i++)
        {
            int x;
            cin>>x;
            for(int j=1; j<=x; j++)
            {
                int y;
                cin>>y;
                ///from y to i+n connected
                graph[y][i+n]=1;
            }
            ///from problem to sink
            graph[i+n][tt]=1;
        }
        ///making graph is done...
        ///now max flow
        int ans = ford_fulkerson(0,tt);
        if(ans==sum)
        {
            cout<<1<<endl;
            for(int i=1; i<=n; i++)
            {
                int cnt=0;
                for(int j=1; j<=m; j++)
                {
                    if(graph[j+n][i]==1)
                    {
                        cnt++;
                        if(cnt>1)
                            cout<<" "<<j;
                        else
                            cout<<j;
                    }
                }
                cout<<endl;
            }
        }
        else
        {
            cout<<0<<endl;
        }
    }
    return 0;
}
/*
Sample Input
3 15
3 3 4
2 1 2
1 3
1 3
1 3
1 3
3 1 2 3
2 2 3
2 1 3
1 2
1 2
2 1 2
2 1 3
2 1 2
1 1
3 1 2 3
3 15
7 3 4
2 1 2
1 1
1 2
1 2
1 3
3 1 2 3 2 2 3
2 2 3
1 2
1 2
2 2 3
2 2 3
2 1 2
1 1
3 1 2 3
0 0

Sample Output
1
8 11 12
1 6 7
2 3 4 5
0
*/
