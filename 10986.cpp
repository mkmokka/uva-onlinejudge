/*
10986 - Sending email
*/

#include<bits/stdc++.h>
using namespace std;
#define INF 1<<30

struct node
{
    int u;
    int cost;
    node(int _u,int _cost)
    {
        u =_u;
        cost =_cost;
    }
    bool operator<(const node& p)const
    {
        return cost>p.cost;
    }
};

void dijkstra(int n,vector<int>graph[],vector<int>cost[],int source,int dest)
{
    int distance[n+1];
    for(int i=0; i<=n; i++)
    {
        distance[i]=INF;
    }
    priority_queue<node>q;
    q.push(node(source,0));
    distance[source]=0;
    while(!q.empty())
    {
        node top = q.top();
        q.pop();
        int u = top.u;
        for(int i=0; i<(int)graph[u].size(); i++)
        {
            int v = graph[u][i];
            if(distance[u]+cost[u][i]<distance[v])
            {
                distance[v]=distance[u]+cost[u][i];
                q.push(node(v,distance[v]));
            }
        }
    }
    if(distance[dest]==INF)
    {
        cout<<"unreachable"<<endl;
    }
    else
    {
        cout<<distance[dest]<<endl;
    }

}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int tc,cas=0;
    cin>>tc;
    while(tc--)
    {
        int node,edge,s,t;
        vector<int>graph[20000+5],cost[20000+5];
        cin>>node>>edge>>s>>t;
        for(int i=0; i<edge; i++)
        {
            int u,v,c;
            cin>>u>>v>>c;
            graph[u].push_back(v);
            graph[v].push_back(u);
            cost[u].push_back(c);
            cost[v].push_back(c);
        }
        cout<<"Case #"<<(++cas)<<": ";
        dijkstra(node,graph,cost,s,t);
    }
    return 0;
}
/*
Sample Input
3
2 1 0 1
0 1 100
3 3 2 0
0 1 100
0 2 200
1 2 50
2 0 0 1

Sample Output
Case #1: 100
Case #2: 150
Case #3: unreachable
*/
