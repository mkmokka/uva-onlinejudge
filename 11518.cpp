/*
11518 - Dominos 2
*/

#include<bits/stdc++.h>
using namespace std;
typedef vector<int> v;
typedef vector<v> vv;

void dfs(const vv&mat, v&vis, int node)
{
    if(vis[node])
        return;
    vis[node]=1;
    for(int i=mat[node].size()-1; i>=0; i--)
    {
        int v = mat[node][i];
        if(vis[v]==0)
        {
            dfs(mat,vis,v);
        }
    }
}

int main()
{
    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    int t,n,m,l,x,y;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>l;
        vv mat(n+1);
        v vis(n+1,false);
        for(int i=0; i<m; i++)
        {
            cin>>x>>y;
            mat[x].push_back(y);
        }
        int cnt=0;
        for(int i=0; i<l; i++)
        {
            cin>>x;
            if(vis[x]==0)
            {
                dfs(mat,vis,x);
            }
        }
        for(int i=1; i<=n; i++)
        {
            cnt+=vis[i];
        }
        cout<<cnt<<endl;
    }
    return 0;
}
/*
Sample Input
1
3 2 1
1 2
2 3
2

Sample Output
2
*/
