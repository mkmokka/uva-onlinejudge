/*
657 - The die is cast
*/
#include<bits/stdc++.h>
using namespace std;

int dx[]= {1,0,-1,+0};
int dy[]= {0,1,+0,-1};
char s[53][53];
int n,m,cnt;

void dfs1(int x,int y)
{
    if(x<0 || y<0 || x>=m || y>=n ||s[x][y]!='X')return;
    s[x][y]='*';
    for(int i=0; i<4; i++)
    {
        int px = x+dx[i];
        int py = y+dy[i];
        dfs1(px,py);
    }
}

void dfs(int x,int y)
{
    if(x<0 || y<0 || x>=m || y>=n ||s[x][y]=='.')return;
    if(s[x][y]=='X')
    {
        cnt++;
        dfs1(x,y);
    }
    ///s[x][y]="*"
    s[x][y]='.';
    for(int i=0; i<4; i++)
    {
        int px = x+dx[i];
        int py = y+dy[i];
        dfs(px,py);
    }
}

void printmatrix()
{
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<s[i][j];
        }
        cout<<endl;
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int tc=1;
    while(cin>>n>>m && !(n==0 && m==0))
    {
        vector<int>ans;
        for(int i=0; i<m; i++)
        {
            cin>>s[i];
        }
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(s[i][j]!='.')
                {
                    cnt=0;
                    dfs(i,j);
                    ans.push_back(cnt);
                    //cout<<cnt<<"    "<<i<<" "<<j<<endl;
                    //printmatrix();
                }
            }
        }
        sort(ans.begin(),ans.end());
        cout<<"Throw "<<(tc++)<<endl;
        cout<<ans[0];
        for(int i=1;i<ans.size();i++){
            cout<<" "<<ans[i];
        }
        printf("\n\n");
        ans.clear();
    }
    return 0;
}

/*
Sample Input
30 15
..............................
..............................
...............*..............
...*****......****............
...*X***.....**X***...........
...*****....***X**............
...***X*.....****.............
...*****.......*..............
..............................
........***........******.....
.......**X****.....*X**X*.....
......*******......******.....
.....****X**.......*X**X*.....
........***........******.....
..............................
0 0

Sample Output
Throw 1
1 2 2 4
*/
