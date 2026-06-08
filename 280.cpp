/*
280 - Vertex
*/
#include<bits/stdc++.h>
using namespace std;
vector<int>graph[10000];
int visit[10000];
int dfs(int u)
{
    queue<int>q;
    q.push(u);
    visit[u]=0;
    int cnt=0;
    while(!q.empty())
    {
        int t = q.front();
        q.pop();
        for(int i=0; i<graph[t].size(); i++)
        {
            int v = graph[t][i];
            if(visit[v]==0)
            {
                cnt++;
                visit[v]=1;
                q.push(v);
            }
        }
    }
    return max(cnt,0);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,x,y,m;
    while(cin>>n)
    {
        if(n==0)
            break;
        while(cin>>x)
        {
            if(x==0)
                break;
            while(cin>>y)
            {
                if(y==0)
                    break;
                graph[x].push_back(y);
            }
        }
        cin>>m;
        for(int i=1; i<=m; i++)
        {
            cin>>y;
            memset(visit,0,sizeof(visit));
            int ans = n - dfs(y);
            cout<<ans;
            if(y>0)
            {
                for(int j=1; j<=n; j++)
                {
                    if(!visit[j])
                    {
                        cout<<" "<<j;
                    }
                }
            }
            cout<<endl;
        }
        for(int i=1; i<=n; i++)
        {
            graph[i].clear();
        }
        memset(visit,0,sizeof(visit));

    }
}
/*
Sample Input
3
1 2 0
2 2 0
3 1 2 0
0
2 1 2
0

Sample Output
2 1 3
2 1 3
*/
