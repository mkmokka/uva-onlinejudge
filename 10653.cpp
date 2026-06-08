/*
10653 - Bombs! NO they are Mines!!
*/

#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
int fx[]= {1,-1,0,0};
int fy[]= {0,0,1,-1};
#define MX 1003
int cell[MX][MX];
int visited[MX][MX];
int dis[MX][MX];
int row,col;

void bfs(int sx, int sy)
{
    memset(visited,0,sizeof(visited));
    memset(dis,0,sizeof(dis));
    visited[sx][sy]=1;
    dis[sx][sy]=0;
    queue<pii>q;
    q.push(pii(sx,sy));
    while(!q.empty())
    {
        pii top = q.front();
        q.pop();

        for(int k=0; k<4; k++)
        {
            int tx = top.first+fx[k];
            int ty = top.second+fy[k];
            if(tx>=0 && tx<row && ty>=0 && ty<col && visited[tx][ty]==0 && cell[tx][ty]!=-1)
            {
                visited[tx][ty]=1;
                dis[tx][ty] = dis[top.first][top.second]+1;
                q.push(pii(tx,ty));
            }
        }
    }
}

int main()
{
    while(scanf("%d",&row)==1)
    {
        scanf("%d",&col);
        if(row==0 && col==0)
            break;
        int op;
        scanf("%d",&op);
        int rr,r1,place;
        memset(cell,0,sizeof(cell));
        for(int i=0; i<op; i++)
        {
            scanf("%d",&rr);
            scanf("%d",&r1);
            for(int j=0; j<r1; j++)
            {
                scanf("%d",&place);
                cell[rr][place]=-1;
            }
        }
        int s1,s2;
        int e1,e2;
        scanf("%d %d",&s1,&s2);
        scanf("%d %d",&e1,&e2);
        bfs(s1,s2);
        printf("%d\n",dis[e1][e2]);
    }
    return 0;
}
/*
Sample Input
10 10
9
0 1 2
1 1 2
2 2 2 9
3 2 1 7
5 3 3 6 9
6 4 0 1 2 7
7 3 0 3 8
8 2 7 9
9 3 2 3 4
0 0
9 9
0 0

Sample Output
18
*/
