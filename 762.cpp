/*
762 - We Ship Cheap
*/

#include<bits/stdc++.h>
using namespace std;

map<string,int>visited;
map<string, string > path;
int bfs(string a, string b,map<string,vector<string> > graph)
{

    queue<string>q;
    q.push(a);
    visited[a]=1;
    while(!q.empty())
    {
        string top = q.front();
        q.pop();
        if(top==b)
            return visited[b];
        int size = graph[top].size();
        for(int i=0; i<size; i++)
        {
            string v = graph[top][i];
            if(visited[v]==-1)
            {
                visited[v]=1;
                visited[v] = visited[top]+1;
                path[v] = top;
                q.push(v);
            }
        }
    }
    return -1;

}
void roadprint(string a, string b)
{
    if(a==b)
        return;
    roadprint(path[a],b);
    cout<<path[a]<<" "<<a<<endl;

}


int main()
{
    int node;
    bool flag=false;
    while(scanf("%d",&node)==1)
    {
        map<string, vector<string> > graph;
        map<string,string>::iterator it;
        string a,b,start,end;
        for(int i=0; i<node; i++)
        {
            cin>>a>>b;
            graph[a].push_back(b);
            graph[b].push_back(a);
            visited[a]=-1;
            visited[b]=-1;
        }
        cin>>start>>end;
        if(flag==true)
            cout<<endl;
        flag=true;
        if(bfs(start,end,graph)!=-1)
        {
            roadprint(end,start);
        }
        else
            cout<<"No route"<<endl;
    }
}
/*
Sample input
3
JV PT
KA PT
KA HP
JV HP

2
JV PT
KA HP
JV HP

Sample output

JV PT
PT KA
KA HP

No route
*/
