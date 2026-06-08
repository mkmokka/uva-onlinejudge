/*
11749 - Poor Trade Advisor
*/

#include<bits/stdc++.h>
using namespace std;

int mat[505][505];
int vis[505];
int max_pda,n,m;
set<int>connected;

void dfs(int node)
{

    for(int i=1; i<=n; i++)
    {
        if(mat[node][i]==max_pda && vis[i]==0)
        {
            vis[node]=vis[i]=1;
            connected.insert(node);
            connected.insert(i);
            dfs(i);
        }
    }
}
void reset_mat()
{
    for(int i=0; i<505; i++)
    {
        for(int j=0; j<505; j++)
        {
            mat[i][j]=INT_MIN;
        }
    }
}
int main()
{
    int x,y,c;
    while(cin>>n>>m)
    {
        if(n==0 && m==0)break;
        max_pda=INT_MIN;
        reset_mat();
        for(int i=0; i<m; i++)
        {
            cin>>x>>y>>c;
            if(mat[x][y]<c)
            {
                mat[x][y]=mat[y][x]=c;
            }
            max_pda=max(max_pda,c);
        }
        int max_area=0;
        memset(vis,0,sizeof(vis));
        for(int i=1; i<=n; i++)
        {
            if(vis[i]==0)
            {
                connected.clear();
                dfs(i);
                max_area=max(max_area,(int)connected.size());
            }
        }
        cout<<max_area<<endl;
    }
    return 0;
}

/*
Sample Input
4 5
1 2 100
1 3 100
1 4 1
2 3 100
3 4 1
9 14
1 2 9
6 9 8
2 4 9
2 3 9
4 5 1
4 3 9
5 9 2
9 8 9
7 8 9
7 9 5
6 7 9
5 6 4
5 8 7
7 5 9
0 0

Sample Output
3
5
*/
