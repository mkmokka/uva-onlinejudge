/*
10034 - Freckles
*/
#include<bits/stdc++.h>
using namespace std;
vector<pair<double,pair<int,int>>>p;
double x[101],y[101];
int parent[101];

int findd(int i)
{
    return (parent[i]==i)?i:findd(parent[i]);
}

void initializer(int n)
{
    for(int i=0; i<n; i++)
    {
        parent[i]=i;
    }
}


double kruskals()
{
    double min_cost=0;
    for(int i=0; i<p.size(); i++)
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
    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    int t,n;
    cin>>t;
    bool gaps=false;
    while(t--)
    {
        if(gaps)printf("\n");
        gaps=true;
        cin>>n;
        initializer(n);
        p.clear();
        for(int i=0; i<n; i++)
        {
            cin>>x[i]>>y[i];
        }
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                double diff = sqrt((x[i]-x[j])*(x[i]-x[j])*1.0+(y[i]-y[j])*(y[i]-y[j])*1.0);
                p.push_back(make_pair(diff,make_pair(i,j)));
            }
        }
        sort(p.begin(),p.end());
        double ans = kruskals();
        cout<<fixed<<setprecision(2)<<ans<<endl;
    }
    return 0;
}
/*
Sample Input
1
3
1.0 1.0
2.0 2.0
2.0 4.0

Sample Output
3.4
*/
