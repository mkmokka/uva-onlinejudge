/*
10557 - XYZZY
*/

#include<bits/stdc++.h>
using namespace std;

vector<int>graph[105];
bool visit[105];
int n;
int dist[105];
int energy[105];

bool bfs(int u)
{
    visit[u]=true;
    queue<int>q;
    q.push(u);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        if(u==n)
            return true;
        for(int i=0; i<graph[u].size(); i++)
        {
            if(!visit[graph[u][i]])
            {
                visit[graph[u][i]]=true;
                q.push(graph[u][i]);
            }
        }
    }
    return false;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin>>n && n>0)
    {
        int e,room;
        for(int i=1; i<=n; i++)
        {
            cin>>e>>room;
            graph[i].clear();
            energy[i]=e;
            for(int j=0; j<room; j++)
            {
                int x;
                cin>>x;
                graph[i].push_back(x);
            }
        }
        dist[1]=100;
        for(int i=2; i<=n; i++)
        {
            dist[i]=-(1e6+7);
        }
        ///here we find all distance based cost from 1 to n
        for(int i=0; i<n-2; i++)
        {
            for(int u=1; u<=n; u++)
            {
                for(int j=0; j<graph[u].size(); j++)
                {
                    int v = graph[u][j];
                    int d = energy[u];
                    if(dist[u]+d>0)
                    {
                        dist[v]=max(dist[v],dist[u]+d);
                    }
                }
            }
        }
        ///if cost is still positive then we have a clear path
        if(dist[n]>0)
        {
            cout<<"winnable"<<endl;
        }///else we must go for further steps
        else
        {
            bool possible =false;
            ///again checking if the cost is still update_able
            ///which means we have a cycle
            ///and after finding a cycle if we able to reach n
            ///then this is winnable
            for(int u=1; u<=n && !possible ; u++)
            {
                for(int j=0; j<graph[u].size(); j++)
                {
                    int v = graph[u][j];
                    int d = energy[u];
                    if(dist[u]+d>0 && dist[v]<dist[u]+d)
                    {
                        for(int i=1; i<=n; i++)
                        {
                            visit[i]=false;
                        }
                        if(bfs(u))
                        {
                            possible=true;
                            break;
                        }
                    }
                }
            }
            if(possible)
            {
                cout<<"winnable"<<endl;
            }
            else
            {
                cout<<"hopeless"<<endl;
            }
        }

    }
    return 0;
}

/*
Sample Input
5
0 1 2
-60 1 3
-60 1 4
20 1 5
0 0
5
0 1 2
20 1 3
-60 1 4
-60 1 5
0 0
5
0 1 2
21 1 3
-60 1 4
-60 1 5
0 0
5
0 1 2
20 2 1 3
-60 1 4
-60 1 5
0 0
-1

Sample Output
hopeless
hopeless
winnable
winnable
*/
