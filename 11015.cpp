/*
11015 - 05-2 Rendezvous
*/

/// Algorithm : Floyd-Warshall

#include<bits/stdc++.h>
using namespace std;
int graph[25][25];
int n,m;
typedef long long ll;
void floyd_warshall()
{
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(graph[i][j]>(ll)graph[i][k]+(ll)graph[k][j])
                    graph[i][j]=graph[i][k]+graph[k][j];
            }
        }
    }

}

int main()
{
    int tc=1;
    while(scanf("%d %d",&n,&m)==2)
    {
        if(n==0)
            break;
        vector<string>name(n+1);
        for(int i=1; i<=n; i++)
        {
            cin>>name[i];
        }
        int a,b,cost;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                graph[i][j]=INT_MAX;
            }
        }
        for(int i=1;i<=n;i++){
            graph[i][i]=0;
        }
        for(int i=0; i<m; i++)
        {
            scanf("%d %d %d",&a,&b,&cost);
            {
                graph[a][b]=cost;
                graph[b][a]=cost;
            }

        }
        floyd_warshall();
        ll sum = INT_MAX;
        int ans_for =0;
        for(int i=1; i<=n; i++)
        {
            ll ans = 0 ;
            for(int j=1; j<=n; j++)
            {
                {
                    ans+=graph[i][j];
                }

            }
            if(ans<sum)
            {
                sum = ans;
                ans_for=i;
            }
        }
        cout<<"Case #"<<tc++<<" : "<<name[ans_for]<<endl;
    }
}
/*
Sample Input
4 3
timotius
harry
richard
januar
1 2 10
1 3 8
1 4 6
4 3
rocky
herwin
gaston
jefry
1 2 5
1 3 5
1 4 5
0 0

Sample Output
Case #1 : timotius
Case #2 : rocky
*/

