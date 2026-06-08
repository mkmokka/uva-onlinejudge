/*
10505 - Montesco vs Capuleto
*/

#include<bits/stdc++.h>
using namespace std;
typedef vector<int>vt;

vector<int>graph[205];
vector<bool>visited;
vector<int>parent;
vector<int>distence;
bool isbipartite;
int zero;
int one;

void count_val()
{
    for(int i=0; i<distence.size(); i++)
    {
        if(distence[i]==0)
            zero++;
        else if(distence[i]==1)
            one++;
    }
}
void set_zero(int node)
{
    parent.assign(node,-1);
    distence.assign(node,-1);
    zero=0;
    one=0;
}
void bfs(int start)
{
    int current,next;
    unsigned int i;
    queue<int>vertices;
    distence[start]=0;
    visited[start]=true;
    vertices.push(start);
    isbipartite=true;
    while(!vertices.empty())
    {
        current = vertices.front();
        vertices.pop();
        for(i=0; i<graph[current].size(); i++)
        {
            next = graph[current][i];
            if(!visited[next])
            {
                visited[next]=true;
                parent[next]=current;
                distence[next]=1-distence[current];
                vertices.push(next);
            }
            else if(distence[next]==distence[current])
            {
                isbipartite=false;
                //  break;
            }
        }
    }
}
int main()
{
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
    int tc,node,total;
    while (~scanf("%d", &tc))
    while(tc--)
    {
        total=0;
        scanf("%d",&node);
        // graph.assign(2*node,vt());
        for(int i=0; i<node; i++)
        {
            graph[i].clear();
        }
        visited.assign(node,false);
        for(int i=0; i<node; i++)
        {
            int vtx,enemies;
            scanf("%d",&enemies);
            for(int j=0; j<enemies; j++)
            {
                scanf("%d",&vtx);
                vtx--;
                if(vtx>=node)continue;
                graph[i].push_back(vtx);
                graph[vtx].push_back(i);
            }
        }
        set_zero(node);
        for(int x=0; x<node; x++)
        {
            if(visited[x]==false)
            {
                set_zero(node);
                bfs(x);
                if(isbipartite)
                {
                    count_val();
                    int tmp = max(zero,one);
                    total+=tmp;
                }
            }
        }
        printf("%d\n",total);
        visited.clear();

        // set_free();
    }
    return 0;
}
/*
Sample Input
3

5
1 3
1 1
0
1 5
0

8
2 4 5
2 1 3
0
0
0
1 3
0
1 5

3
2 2 3
1 3
1 1

Sample Output
3
5
0
*/
