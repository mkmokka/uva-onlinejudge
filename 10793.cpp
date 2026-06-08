/*
10793 - The Orc Attack
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,l,d,tc=0;
    cin>>t;
    while(t--)
    {
        cin>>l>>d;
        vector<vector<int>>graph(l,vector<int>(l,INT_MAX));
        for(int i=0; i<l; i++)
        {
            graph[i][i]=0;
        }
        for(int i=0; i<d; i++)
        {
            int x,y,c;
            cin>>x>>y>>c;
            --x;
            --y;
            graph[x][y]=graph[y][x]=min(c,graph[x][y]);
        }
        for(int k=0; k<l; k++)
        {
            for(int i=0; i<l; i++)
            {
                for(int j=0; j<l; j++)
                {
                    if(graph[i][k]!=INT_MAX && graph[k][j]!=INT_MAX)
                        graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
                }
            }
        }
        ///if we get 5 values same then this is the  minimum
        ///possible distance from the farthest point.
        int ans = INT_MAX;
        int idx=-1;
        for(int i=0; i<l; i++)
        {
            bool isvalid=true;
            for(int j=0; j<5; j++)
            {
                if(graph[j][i]!=graph[0][i])
                    isvalid=false;
            }
            if(isvalid)
            {
                int maxval =  graph[i][max_element(graph[i].begin(),graph[i].end())-graph[i].begin()];
                if(maxval<ans)
                {
                    ans=maxval;
                    idx=i;
                }
            }
        }
        cout<<"Map "<<(++tc)<<": ";
        if(idx!=-1)
        {
            cout<<ans<<endl;
        }
        else
        {
            cout<<-1<<endl;
        }

    }
    return 0;
}
/*
Sample Input
2
7 11
1 7 2
2 7 2
3 7 2
5 7 2
6 7 1
1 6 1
2 6 1
3 6 1
4 6 1
5 6 1
7 6 1
6 1
1 2 3

Sample Output
Map 1: 1
Map 2: -1
*/
