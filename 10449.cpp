/*
10449 - Traffic
*/

#include<bits/stdc++.h>
using namespace std;
const int INF = 1e8+9;
struct node
{
    int a,b,cost;
} graph[2020];

int cost[2020];
int dist[2020];
int n,m;
void bellman_ford()
{

    for(int i=0; i<=210; i++)
    {
        dist[i]=INF;
    }
    dist[1]=0;
    for(int i=0; i<n-1; i++)
    {
        bool update =false;
        for(int j=1; j<=m; j++)
        {
            int u = graph[j].a;
            int v = graph[j].b;
            if(dist[u]+graph[j].cost<dist[v] && dist[u]!=INF)
            {
                dist[v]=dist[u]+graph[j].cost;
                update=true;
            }
        }
        if(update==false)
            break;
    }
    ///checking for negative cycle
    for(int j=1; j<=m; j++)
    {
        int u = graph[j].a;
        int v = graph[j].b;
        if(dist[u]+graph[j].cost<dist[v] && dist[u]!=INF)
        {
            dist[v]=-INF;
        }
    }
    int q,in;
    cin>>q;
    for(int i=1; i<=q; i++)
    {
        cin>>in;
        if(dist[i]==INF || dist[i]<3)
        {
            cout<<"?"<<endl;
        }
        else
        {
            cout<<dist[in]<<endl;
        }
    }

}


int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tc=0,u,v,c;
    while(cin>>n)
    {
        for(int i=1; i<=n; i++)
        {
            cin>>cost[i];
        }
        cin>>m;
        for(int i=1; i<=m; i++)
        {
            cin>>u>>v;
            int temp = (cost[v]-cost[u])*(cost[v]-cost[u])*(cost[v]-cost[u]);
            graph[i].a=u;
            graph[i].b=v;
            graph[i].cost=temp;
        }
        cout<<"Set #"<<(++tc)<<endl;
        bellman_ford();
    }
    return 0;
}

/*
Sample Input
5 6 7 8 9 10
6
1 2
2 3
3 4
1 5
5 4
4 5
2
4
5

Sample Output
Set #1
3
4
*/
