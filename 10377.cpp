/*
10377 - Maze Traversal
*/
#include<bits/stdc++.h>
using namespace std;

char directions[]= {'N','E','S','W'};
int dx[]= {-1, +0, +1, +0};
int dy[]= {+0, +1, +0, -1};

int main()
{

    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    int t,init_x,init_y,r,c;
    scanf("%d\n",&t);
    while(t--)
    {
        string s;
        cin>>r>>c;
        cin.ignore();
        vector<vector<char>>graph(r+1,vector<char>(c+1));
        for(int i=1; i<=r; i++)
        {
            getline(cin,s);
            for(int j=1; j<=c; j++)
            {
                graph[i][j]=s[j-1];
            }
        }
        cin>>init_x>>init_y;
        cin.ignore();
        int initial_dir=0;
        bool found=false;
        while(getline(cin,s))
        {
            s.erase(remove(s.begin(),s.end(),' '),s.end());
            for(int i=0; i<s.size(); i++)
            {
                if(s[i]=='R')
                {
                    initial_dir=(initial_dir+1)%4;

                }
                else if(s[i]=='L')
                {
                    initial_dir=(initial_dir+3)%4;
                }
                else if(s[i]=='F')
                {
                    int px = init_x+dx[initial_dir];
                    int py = init_y+dy[initial_dir];
                    if(graph[px][py]!='*')
                    {
                        init_x=px;
                        init_y=py;
                    }
                }
                else if(s[i]=='Q')
                {
                    cout<<init_x<<" "<<init_y<<" "<<directions[initial_dir]<<endl;
                    found=true;
                    break;
                }
            }
            if(found)
                break;
        }
        if(t)printf("\n");
    }
    return 0;
}
/*
Stay concern to taking inputs because there is space in input.
1
7 8
********
* * * **
* *    *
* * ** *
* * *  *
*   * **
********
2 4
RRFLFF FFR
FF
RFFQ
*/
