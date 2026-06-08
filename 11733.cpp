/*
11733 - Airports
*/

#include<bits/stdc++.h>
using namespace std;
const int MX = 1e5+5;
vector<pair<int,pair<int,int> > >v,ans;
int parent[MX];
void init(int n)
{
    for(int i=0; i<=n; i++)
    {
        parent[i]=i;
    }
}
int root(int x)
{
    if(x!=parent[x])
    {
        return parent[x]=root(parent[x]);
    }
    else
        return x;
}
void union_set(int i, int j)
{
    int px = root(i);
    int py = root(j);
    if(px!=py)
    {
        parent[px]=py;
    }

}
int node,edge,tc;
void kruskal(vector<pair<int,pair<int,int> > >p)
{
    int x,y;
    for(int i=0; i<edge && v[i].first<tc; i++)
    {
        x = p[i].second.first;
        y = p[i].second.second;
        if(root(x)!=root(y))
        {
            union_set(x,y);
            ans.push_back(p[i]);
        }
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int j=1; j<=t; j++)
    {
        v.clear();
        ans.clear();
        int x,y,weight;
        scanf("%d %d %d",&node,&edge,&tc);
        init(node);
        for(int i=0; i<edge; i++)
        {
            scanf("%d %d %d",&x,&y,&weight);
            v.push_back(make_pair(weight,make_pair(x,y)));
        }
        sort(v.begin(),v.end());
        kruskal(v);
        int cost =0,cnt=0;
        for(int i=0; i<ans.size(); i++)
        {
            cost+=ans[i].first;
            ///cout<<ans[i].first<<endl;
        }
        for(int i=1; i<=node; i++)
        {
            if(parent[i]==i)
                cnt++;
        }
        printf("Case #%d: %d %d\n",j,cost+cnt*tc,cnt);
    }
    return 0;
}
/*
Sample Input
2
4 4 100
1 2 10
4 3 12
4 1 41
2 3 23
5 3 1000
1 2 20
4 5 40
3 2 30

Sample Output
Case #1: 145 1
Case #2: 2090 2

*/
