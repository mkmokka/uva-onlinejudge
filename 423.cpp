/*
423 - MPI Maelstrom
*/

#include<bits/stdc++.h>
using namespace std;
int n;
long long graph[101][101];
int main()
{
    while(scanf("%d",&n)==1){
    for(int i=0; i<n; i++)
    {

        for(int j=0; j<=i; j++)
        {
            char digit[1005];
            if(i==j)
            {
                graph[i][j]=0;
            }
            else
            {
                cin>>digit;
                if(digit[0]=='x')
                {
                    graph[i][j]=INT_MAX;
                }
                else
                {
                    graph[i][j]=atoi(digit);

                }
                graph[j][i]=graph[i][j];
            }
        }
    }
    /// using floyd warshall algorithm
    for(int k=0; k<n; k++)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                graph[i][j] = min(graph[i][j],graph[i][k]+graph[k][j]);
            }
        }
    }
    long long ans = 0;
    for(int i=0; i<n; i++)
    {
        ans = max(ans,graph[0][i]);
    }
    cout<<ans<<endl;
    }
}

/*
Sample Input
5
50
30 5
100 20 50
10 x x 10

Sample Output
35
*/
