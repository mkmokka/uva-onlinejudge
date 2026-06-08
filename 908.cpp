/*
908 - Re-connecting Computer Sites
*/

#include<bits/stdc++.h>
using namespace std;
vector<pair<int,pair<int,int>>>p;
int parent[1000001];

void initialize(int n)
{
    for(int i=0; i<=n; i++)
    {
        parent[i]=i;
    }
}

int findd(int i)
{
    return (parent[i]==i)?i:findd(parent[i]);
}

int kruskal(int n)
{
    int min_cost =0;
    for(int i=0; i<n; i++)
    {
        int px = findd(p[i].second.first);
        int py = findd(p[i].second.second);
        if(px!=py)
        {
            parent[px]=py;
            min_cost+=p[i].first;
        }
    }
    return min_cost;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,k,m,loop,x,y,c;
    int t=0;
    while(cin>>n)
    {
        if(t)
            printf("\n");
        t=1;
        int cost1=0;
        for(int i=0; i<n-1; i++)
        {
            cin>>x>>y>>c;
            cost1+=c;
        }
        cin>>k;
        for(int i=0; i<k; i++)
        {
            cin>>x>>y>>c;
            p.push_back(make_pair(c,make_pair(x,y)));
        }
        cin>>m;
        for(int i=0; i<m; i++)
        {
            cin>>x>>y>>c;
            p.push_back(make_pair(c,make_pair(x,y)));
        }
        loop = m+k;
        initialize(loop);
        sort(p.begin(),p.end());
        int cost2 = kruskal(loop);
        cout<<cost1<<endl;
        cout<<cost2<<endl;
        p.clear();

    }
    return 0;
}

/*
Sample Input
5
1 2 5
1 3 5
1 4 5
1 5 5
1
2 3 2
6
1 2 5
1 3 5
1 4 5
1 5 5
3 4 8
4 5 8

Sample Output
20
17
*/
