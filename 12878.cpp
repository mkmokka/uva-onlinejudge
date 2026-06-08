/*
12878 - Flowery Trails
*/

#include<bits/stdc++.h>
using namespace std;

#define MX 10005
vector<pair<int,int>>graph[MX];
int dist1[MX];
int dist2[MX];
int n,m;
void bellman_ford(int u)
{
    queue<int>q;
    q.push(u);
    dist1[u]=0;
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        for(int i=0; i<graph[u].size(); i++)
        {
            int v = graph[u][i].first;
            int c = graph[u][i].second;
            if(dist1[v]>dist1[u]+c)
            {
                dist1[v]=dist1[u]+c;
                q.push(v);
            }
        }
    }
    return;
}

void bellman_ford2(int u)
{
    queue<int>q;
    q.push(u);
    dist2[u]=0;
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        for(int i=0; i<graph[u].size(); i++)
        {
            int v = graph[u][i].first;
            int c = graph[u][i].second;
            if(dist2[v]>dist2[u]+c)
            {
                dist2[v]=dist2[u]+c;
                q.push(v);
            }
        }
    }
    return;
}

int main()
{
    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    while(cin>>n>>m)
    {
        for(int i=0; i<n; i++)
            graph[i].clear();
        int x,y,c;
        for(int i=0; i<m; i++)
        {
            cin>>x>>y>>c;
            graph[x].push_back(make_pair(y,c));
            graph[y].push_back(make_pair(x,c));
        }
        for(int i=0; i<n; i++)
        {
            dist1[i]=INT_MAX;
            dist2[i]=INT_MAX;
        }
        bellman_ford(0);
        bellman_ford2(n-1);
        int min_cost = dist1[n-1];
        long long ans =0;
        for(int i=0; i<n; i++)
        {
            x=i;
            for(int j=0; j<graph[i].size(); j++)
            {
                y=graph[i][j].first;
                c=graph[i][j].second;
                if(dist1[x]+c+dist2[y]==min_cost)
                {
                    ans+=c;
                }
            }
        }
        cout<<2*ans<<endl;
    }
    return 0;
}

/*
Sample Input
10 15
0 1 580
1 4 90
1 4 90
4 9 250
4 2 510
2 7 600
7 3 200
3 3 380
3 0 150
0 3 100
7 8 500
7 9 620
9 6 510
6 5 145
5 9 160
4 7
0 1 1
0 2 2
0 3 10
0 3 3
1 3 2
2 3 1
1 1 1

Sample Output
3860
18
*/
