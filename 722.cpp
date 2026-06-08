/*
722 - Lakes
*/
#include<bits/stdc++.h>
using namespace std;

int dx[]= {1,0,-1,+0};
int dy[]= {0,1,+0,-1};
char tmp[100];
char adj[100][100];
bool vis[100][100];
int n,m,cnt;

int dfs(int x,int y)
{
    if(x<0 || y<0 || x>=n || y>=m || vis[x][y] || adj[x][y]=='1')
        return 0;
    vis[x][y]=true;
    cnt++;
    for(int i=0; i<4; i++)
    {
        int px = x+dx[i];
        int py = y+dy[i];
        dfs(px,py);
    }
    return cnt;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t,a,b;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        --a;
        --b;
        n=0;
        memset(vis,false,sizeof(vis));
        getchar();
        while(gets(tmp) && strlen(tmp)>0)
        {
            strcpy(adj[n],tmp);
            n++;
        }
        m= strlen(adj[0]);
        cnt=0;
        ///cout<<n<<" "<<m<<endl;
        int ans = dfs(a,b);
        cout<<ans<<endl;
        if(t){
            cout<<endl;
        }
    }
    return 0;
}

/*
Sample Input
1

02 01
1001101
0011111
0001001
1100011
1111111
1100110
1110111


Sample Output
12
*/
