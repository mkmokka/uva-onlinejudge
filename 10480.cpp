/*
10480 - Sabotage
*/

#include<bits/stdc++.h>
using namespace std;

int n,m;
bool bfs(vector<vector<int>>&rgraph,int s,int t,int parent[])
{
    bool visited[n]= {false};
    queue<int>q;
    q.push(s);
    parent[s]=-1;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int v=0; v<n; v++)
        {
            if(visited[v]==false && rgraph[u][v]>0)
            {
                if(v==t)
                {
                    parent[v]=u;
                    return true;
                }
                q.push(v);
                parent[v]=u;
                visited[v]=true;
            }
        }
    }
    return false;
}
void dfs(vector<vector<int>>&rgraph,int s,bool visited[])
{
    visited[s]=true;
    for(int i=0; i<n; i++)
    {
        if(rgraph[s][i]>0 && !visited[i])
        {
            dfs(rgraph,i,visited);
        }
    }
    return;
}

void minimum_cut(vector<vector<int>>&graph,int s,int t)
{
    int u,v;
    vector<vector<int>>rgraph(n,vector<int>(n,0));
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            rgraph[i][j]=graph[i][j];
        }
    }
    int parent[n];
    int max_flow=0;
    while(bfs(rgraph,s,t,parent))
    {
        int path_flow=INT_MAX;
        for(v=t; v!=s; v=parent[v])
        {
            u=parent[v];
            path_flow=min(path_flow,rgraph[u][v]);
        }
        for(v=t; v!=s; v=parent[v])
        {
            u=parent[v];
            rgraph[u][v]-=path_flow;
            rgraph[v][u]+=path_flow;
        }
        max_flow+=path_flow;
    }
    bool visited[n]= {false};
    dfs(rgraph,s,visited);
    int min_cut=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(visited[i] && !visited[j] && graph[i][j])
            {
                cout<<i<<" "<<j<<endl;
                min_cut+=graph[i][j];
            }
        }
    }
    cout<<endl;
    return;
}

int main()
{
    while(cin>>n>>m && !(m==0 && n==0))
    {
        n++;
        vector<vector<int>>graph(n,vector<int>(n,0));
        for(int i=1; i<=m; i++)
        {
            int x,y,c;
            cin>>x>>y>>c;
            graph[x][y]+=c;
            graph[y][x]+=c;
        }
        minimum_cut(graph,1,2);
    }
}

/*
Sample Input
5 8
1 4 30
1 3 70
5 3 20
4 3 5
4 5 15
5 2 10
3 2 25
2 4 50
5 8
1 4 30
1 3 70
5 3 20
4 3 5
4 5 15
5 2 10
3 2 25
2 4 50
0 0

Sample Output
4 1
3 4
3 5
3 2

4 1
3 4
3 5
3 2
*/

