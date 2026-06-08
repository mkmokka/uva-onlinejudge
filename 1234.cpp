/*
1234 - RACING
*/
#include<bits/stdc++.h>
using namespace std;
vector<pair<int,pair<int,int>>>p;
int parent[10005];
int n,m;

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


int main()
{
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        int sum=0;
        for(int i=0; i<m; i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            p.push_back(make_pair(c,make_pair(a,b)));
            sum+=c;
        }
        sort(p.rbegin(),p.rend());
        initialize(n);
        for(int i=0; i<m; i++)
        {
            int px = findd(p[i].second.first);
            int py = findd(p[i].second.second);
            if(px!=py)
            {
                sum-=p[i].first;
                parent[px]=py;
            }
        }
        cout<<sum<<endl;
        p.clear();
    }
    return 0;
}

/*
Sample Input
1
6 7
1 2 5
2 3 3
1 4 5
4 5 4
5 6 4
6 3 3
5 2 3
0

Sample Output
6
*/
