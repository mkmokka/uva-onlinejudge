/*
10116 - Robot Motion
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
   /// freopen("input.txt", "r", stdin);
   /// freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,s;
    while(cin>>n>>m>>s)
    {
        if(n==0 && m==0 && s==0)
            break;
        char mat[20][20];
        int vis[20][20];
        for(int i=0; i<n; i++)
        {
            cin>>mat[i];
        }
        memset(vis,-1,sizeof(vis));
        int x=0,y=s-1,step=0;
        vis[x][y]=0;
        while(1)
        {
            step++;
            if(mat[x][y]=='N')
            {
                x--;
            }
            else if(mat[x][y]=='S')
            {
                x++;
            }
            else if(mat[x][y]=='E')
            {
                y++;
            }
            else
            {
                y--;
            }
            if(x<0 || y<0 || x>=n || y>=m)
            {
                cout<<step<<" step(s) to exit"<<endl;
                break;
            }
            if(vis[x][y]!=-1)
            {
                cout<<vis[x][y]<<" step(s) before a loop of "<<step-vis[x][y]<<" step(s)"<<endl;
                break;
            }
            vis[x][y]=step;
        }
    }
    return 0;
}

/*
Sample Input
3 6 5
NEESWE
WWWESS
SNWWWW
4 5 1
SESWE
EESNW
NWEEN
EWSEN
0 0 0

Sample Output
10 step(s) to exit
3 step(s) before a loop of 8 step(s)
*/
