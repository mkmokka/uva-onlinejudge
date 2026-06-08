/*
10596 - Morning Walk
*/
#include<bits/stdc++.h>
using namespace std;

bool check_degree(int n,const vector<int>& degree)
{
    for(int i=0; i<n; i++)
    {
        if(degree[i]%2==1)
        {
            return false;
        }
    }
    return true;
}
void dfs(int n,int i,const vector<vector<bool>>&graph,vector<bool>&visited)
{

    visited[i]=true;
    const vector<bool>&g = graph[i];
    for(int j=0; j<n; j++)
    {
        if(g[j] && !visited[j])
        {
            dfs(n,j,graph,visited);
        }
    }


}
bool check_connection(int n, const vector<int>& degree, const vector<vector<bool>>&graph)
{
    vector<bool>visited(n,false);
    int start;
    for(start=0; start<n; start++)
        if(degree[start])
            break;
    if(start<n)
        dfs(n,start,graph,visited);
    for(int i=0; i<n; i++)
        if(degree[i])
        {
            if(!visited[i])
                return false;
        }
    return true;
}


int main()
{
    int n,r;
    while(cin>>n>>r)
    {
        vector<int>degree(n,0);
        vector<vector<bool> >graph(n,vector<bool>(n,false));
        for(int i=0; i<r; i++)
        {
            int a,b;
            cin>>a>>b;
            degree[a]++;
            degree[b]++;
            graph[a][b]=graph[b][a]=true;
        }
        if(r && check_degree(n,degree) && check_connection(n,degree,graph))
        {
            cout<<"Possible\n";
        }
        else
        {
            cout<<"Not Possible\n";
        }
    }
}

/*
Sample Input
2 2
0 1
1 0
2 1
0 1

Sample Output
Possible
Not Possible
*/
