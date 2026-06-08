/*
10369 - Arctic Network
*/

#include<bits/stdc++.h>
using namespace std;
#define MX 505
vector<pair<double,pair<int,int> > >p;
vector<int>parent(MX);
int x[MX],y[MX];
int size_;

void set_value(int n)
{
    for(int i=0; i<n; i++)
    {
        parent[i]=i;
    }
    size_=n;
}
int findd(int i)
{
    return (parent[i]==i)?i:findd(parent[i]);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int node,edge;
        cin>>node>>edge;
        for(int i=0; i<edge; i++)
        {
            cin>>x[i]>>y[i];
        }
        set_value(edge);
        p.clear();
        for(int i=0; i<edge; i++)
        {
            for(int j=i+1; j<edge; j++)
            {
                double distance = sqrt((x[i]-x[j])*(x[i]-x[j])*1.0+(y[i]-y[j])*(y[i]-y[j])*1.0);
                p.push_back(make_pair(distance,make_pair(i,j)));
            }
        }
        sort(p.begin(),p.end());
        double ans = 0.0;
        for(int i=0; size_>node; i++)
        {
            int px = findd(p[i].second.first);
            int py = findd(p[i].second.second);
            if(px!=py)
            {
                ans = max(ans,p[i].first);
                parent[px]=py;
                size_--;
            }
        }
        cout<<fixed<<setprecision(2)<<ans<<endl;
    }
    return 0;
}
/*
Sample Input
1
2 4
0 100
0 300
0 600
150 750

Sample Output
212.13
*/
