/*
1056 - Degrees of Separation
*/
#include<bits/stdc++.h>
using namespace std;
const int INF = (1e6);

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,m,tc=0,first=0;
    while(cin>>n>>m && !(n==0 && m==0))
    {
        map<string,int>mp;
        vector<vector<int>>graph(n,vector<int>(n,INF));
        int idx=0;
        string one,two;
        int x,y;
        for(int i=0; i<m; i++)
        {
            cin>>one>>two;
            if(mp.find(one)==mp.end())
            {
                mp[one]=idx++;
            }
            x=mp[one];
            if(mp.find(two)==mp.end())
            {
                mp[two]=idx++;
            }
            y = mp[two];

            graph[x][y]=1;
            graph[y][x]=1;
        }
        for(int k=0; k<n; k++)
        {
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
                }
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                ans = max(ans,graph[i][j]);
            }
        }
        if(ans==INF)
        {
            cout<<"Network "<<(++tc)<<": DISCONNECTED"<<endl;
        }
        else
        {
            cout<<"Network "<<(++tc)<<": "<<ans<<endl;
        }
        printf("\n");
    }
    return 0;
}
/*
Sample Input
4 4
Ashok Kiyoshi Ursala Chun Ursala Kiyoshi
Kiyoshi Chun
4 2
Ashok Chun Ursala Kiyoshi
6 5
Bubba Cooter Ashok Kiyoshi Ursala Chun
Ursala Kiyoshi Kiyoshi Chun
0 0

Sample Output
Network 1: 2
Network 2: DISCONNECTED
Network 3: DISCONNECTED
*/
