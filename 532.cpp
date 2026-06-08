/*
532 Dungeon Master
*/


/// BFS 3D grid .....
/*
Given a set of maps which constitute a 3-Dimensional world (a dungeon),
determine whether it is possible to travel from the starting cell (marked as 'S')
to the ending cell (marked as 'E') and calculate the minimal time-cost for the travelling if possible.

As a 3D BFS problem, each cell has 6 possible next move:
{up, down, left, right, previous layer, next layer}
remember to try them all.

*/
#include<bits/stdc++.h>
using namespace std;
bool visited[30][30][30];
vector<vector<string> > adj;
int z,y,x;
int di[]= {-1,1,0,0,0,0};
int dj[]= {0,0,-1,1,0,0};
int dk[]= {0,0,0,0,-1,1};
struct node
{
    int a;
    int b;
    int c;
    int cost;
    node(int x,int y, int z, int w)
    {
        a=x;
        b=y;
        c=z;
        cost=w;
    }
};

void bfs(int a,int b, int c)
{
    memset(visited,false,sizeof(visited));
    queue<node>q;
    q.push(node(a,b,c,0));
    visited[a][b][c]=true;
    int j,k,l,one,two,three;;
    while(!q.empty())
    {
        node aux = q.front();
        q.pop();
        j = aux.a;
        k = aux.b;
        l = aux.c;
        if(adj[l][k][j]=='E')
        {
            printf("Escaped in %d minute(s).\n",aux.cost);
            return;
        }
        for(int i=0; i<6; i++)
        {
            one = j + di[i];
            two = k +dj[i];
            three = l + dk[i];
            if(one>=0 && one<x && two>=0 && two<y && three>=0 && three<z && !visited[one][two][three] && adj[three][two][one]!='#')
            {
                q.push(node(one,two,three,aux.cost+1));
                visited[one][two][three]=true;

            }

        }
    }
    printf("Trapped!\n");
    return;


}



int main()
{
    int pos1,pos2,pos3;
    vector<string>v;
    string s;
    while(1)
    {
        cin>>z>>y>>x;
        if(z==0 && x==0 && y==0)
            break;
        adj.clear();
        for(int i=0; i<z; i++)
        {
            v.clear();
            for(int j=0; j<y; j++)
            {
                cin>>s;
                v.push_back(s);
            }
            adj.push_back(v);
        }
        for(int i=0; i<z; i++)
        {
            for(int j=0; j<y; j++)
            {
                for(int k=0; k<x; k++)
                {
                    if(adj[i][j][k]=='S')
                    {
                        pos1=k;
                        pos2=j;
                        pos3=i;
                        goto xx;

                    }
                }
            }
        }
xx:
        bfs(pos1,pos2,pos3);
    }
    return 0;
}

/*
Sample Input
3 4 5
S....
.###.
.##..
###.#
#####
#####
##.##
##...
#####
#####
#.###
####E

1 3 3
S##
#E#
###

0 0 0

Sample Output
Escaped in 11 minute(s).
Trapped!
*/
