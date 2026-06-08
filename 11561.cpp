/*
11561 - Getting Gold
*/
#include<bits/stdc++.h>
using namespace std;
int row,col,cnt;
char v[105][105];
int vis[105][105];
int dx[]= {-1,+0,+1,+0};
int dy[]= {+0,+1,+0,-1};

void dfs(int a,int b)
{
    if(v[a][b]=='#' || vis[a][b])
        return;
    if(v[a][b]=='G')
        cnt++;
    vis[a][b]=true;
    for(int i=0; i<4; i++)
    {
        int x = dx[i]+a;
        int y = dy[i]+b;
        if(v[x][y]=='T')
            return;
    }
    for(int i=0; i<4; i++)
    {
        int x1 = dx[i]+a;
        int y1 = dy[i]+b;
        dfs(x1,y1);
    }
}

int main()
{
    /// freopen("input.txt", "r", stdin);
    /// freopen("output.txt", "w", stdout);
    while(cin>>row>>col)
    {
        for(int i=0; i<col; i++)
        {
            cin>>v[i];
        }
        memset(vis,false,sizeof(vis));
        bool used =false;
        cnt=0;
        int a,b;
        for(int i=0; i<col; i++)
        {
            for(int j=0; j<row; j++)
            {
                if(v[i][j]=='P')
                {
                    a=i;
                    b=j;
                    used = true;
                    break;
                }
            }
            if(used)
                break;
        }
        dfs(a,b);
        cout<<cnt<<endl;
    }
    return 0;
}
/*
Sample Input
7 4
#######
#P.GTG#
#..TGG#
#######
8 6
########
#...GTG#
#..PG.G#
#...G#G#
#..TG.G#
########

Sample Output
1
4
*/
