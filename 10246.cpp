/*
10246 - Asterix and Obelix
*/

///Algorithm:- Floyd  Warshall
/// using two times
#include<bits/stdc++.h>
using namespace std;
#define inf 100000000
int c,r,q;
int cost[85][85];
int graph[85][85];
void floyd_warshall()
{
    for(int k=1; k<=c; k++)
    {
        for(int i=1; i<=c; i++)
        {
            for(int j=1; j<=c; j++)
            {
                int total = graph[i][k]+graph[k][j];
                int total_c = max(cost[i][k],cost[k][j]);
                if(graph[i][j]+cost[i][j]>total+total_c)
                {
                    graph[i][j]=total;
                    cost[i][j]=total_c;
                }
            }
        }
    }

}

int main()
{
    int a,b,val,tc=1;
    while(1)
    {
        scanf("%d %d %d",&c,&r,&q);
        if(c==0 && r==0 && q==0)
            break;
        for(int i=1; i<=c; i++)
        {
            for(int j=1; j<=c; j++)
            {
                if(i==j)
                {
                    graph[i][j]=0;
                }
                else
                {
                    graph[i][j]=inf;
                }
                cost[i][j]=inf;
            }
        }
        for(int i=1; i<=c; i++)
        {
            scanf("%d",&cost[i][i]);
        }

        for(int i=1; i<=r; i++)
        {
            scanf("%d %d %d",&a,&b,&val);
            graph[a][b]=val;
            graph[b][a]=val;
            cost[a][b]=cost[b][a]=max(cost[a][a],cost[b][b]);
        }
        floyd_warshall();
        floyd_warshall();
        int source,dest;
        if(tc!=1)
            printf("\n");
        printf("Case #%d\n",tc++);
        for(int i=1; i<=q; i++)
        {
            scanf("%d %d",&source,&dest);
            if(graph[source][dest]>=inf)
            {
                printf("%d\n",-1);
            }
            else
            {
                printf("%d\n",graph[source][dest]+cost[source][dest]);
            }
        }

    }
    return 0;
}
/*
Sample Input
7 8 5
2 3 5 15 4 4 6
1 2 20
1 4 20
1 5 50
2 3 10
3 4 10
3 5 10
4 5 15
6 7 10
1 5
1 6
5 1
3 1
6 7
4 4 2
2 1 8 3
1 2 7
1 3 5
2 4 8
3 4 6
1 4
2 3
0 0 0

Sample Output
Case #1
45
-1
45
35
16

Case #2
18
20
*/
