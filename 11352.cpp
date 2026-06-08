/*
11352 - Crazy King
*/

#include<bits/stdc++.h>
using namespace std;
///for king move
int dx[]= {-1,+0,+1,+0,-1,+1,+1,-1};
int dy[]= {+0,+1,+0,-1,-1,-1,+1,+1};
///for horse move
int fx[]= {-2,-2,-1,+1,+2,+2,+1,-1};
int fy[]= {-1,+1,+2,+2,+1,-1,-2,-2};

char graph[101][101];
int movee[101][101];
int visit[101][101];
int n,m;

void bfs(int x,int y)
{
    queue<pair<int,int>>q;
    q.push(make_pair(x,y));
    visit[x][y]=1;
    while(!q.empty())
    {
        pair<int,int> p = q.front();
        q.pop();
        int tempx=p.first;
        int tempy=p.second;
        for(int i=0; i<8; i++)
        {
            int px = tempx+fx[i];
            int py = tempy+fy[i];
            if(px>=0 && px<n && py>=0 && py<m && graph[px][py]=='.')
            {
                if(visit[px][py]==0)
                {
                    visit[px][py]=1;
                }
            }
        }
    }
}

int bfs1(int x,int y)
{
    queue<pair<int,int>>q;
    q.push(make_pair(x,y));
    movee[x][y]=0;
    while(!q.empty())
    {
        pair<int,int> p = q.front();
        q.pop();
        int tempx=p.first;
        int tempy=p.second;
        for(int i=0; i<8; i++)
        {
            int px = tempx+dx[i];
            int py = tempy+dy[i];
            if(px>=0 && px<n && py>=0 && py<m && graph[px][py]=='.')
            {
                if(visit[px][py]==0)
                {
                    q.push(make_pair(px,py));
                    visit[px][py]=1;
                    movee[px][py]=movee[tempx][tempy]+1;
                }
            }
            if(graph[px][py]=='B')
            {
                movee[px][py]=movee[tempx][tempy]+1;
                return movee[px][py];
            }
        }
    }
    return 0;
}


int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int tc;
    cin>>tc;
    while(tc--)
    {
        cin>>n>>m;
        int sourcex,sourcey,destx,desty;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cin>>graph[i][j];
                visit[i][j]=0;
                if(graph[i][j]=='A')
                {
                    sourcex=i;
                    sourcey=j;
                }
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(graph[i][j]=='Z' && visit[i][j]==0)
                {
                    bfs(i,j);
                }
            }
        }
        int ans;
        ans = bfs1(sourcex,sourcey);
        if(ans==0)
        {
            cout<<"King Peter, you can't go now!"<<endl;
        }
        else
        {
            cout<<"Minimal possible length of a trip is "<<ans<<endl;
        }
    }
    return 0;
}
/*
Sample Input
4
5 5
.Z..B
..Z..
Z...Z
.Z...
A....
3 2
ZB
.Z
AZ
6 5
....B
.....
.....
..Z..
.....
A..Z.
3 3
ZZ.
...
AB.

Sample Output
King Peter, you can’t go now!
Minimal possible length of a trip is 2
King Peter, you can’t go now!
Minimal possible length of a trip is 1
*/
