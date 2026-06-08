/*
10462 - Is There A Second Way Left?
*/

#include<bits/stdc++.h>
using namespace std;

vector<pair<int,pair<int,int>>>p;
vector<int>parent(105);
vector<int>tree;
int sizee,node,edge;
void initialize(int n)
{
    for(int i=0; i<n; i++)
    {
        parent[i]=i;
    }
    sizee=n;
}
int findd(int i)
{
    return (parent[i]==i)?i:findd(parent[i]);
}

int kruskal(int idx)
{
    int mst =0;
    initialize(node);
    for(int i=0; i<p.size() && sizee>1; i++)
    {
        if(i==idx)
            continue;
        int px = findd(p[i].second.first);
        int py = findd(p[i].second.second);
        if(px!=py)
        {
            mst+=p[i].first;
            sizee--;
            parent[px]=py;
        }
    }
    return sizee>1?1e9:mst;
}


int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t,tc=0;
    cin>>t;
    while(t--)
    {
        int x,y,c;
        cin>>node>>edge;
        initialize(node);
        p.clear();
        tree.clear();
        for(int i=0; i<edge; i++)
        {
            cin>>x>>y>>c;
            x--;
            y--;
            p.push_back(make_pair(c,make_pair(x,y)));
        }
        sort(p.begin(),p.end());
        int mst=0;
        for(int i=0; i<p.size(); i++)
        {
            int px = findd(p[i].second.first);
            int py = findd(p[i].second.second);
            if(px!=py)
            {
                mst+=p[i].first;
                parent[px]=py;
                sizee--;
                tree.push_back(i);
            }
        }
        cout<<"Case #"<<(++tc)<<" : ";
        if(sizee>1)
        {
            cout<<"No way"<<endl;
            continue;
        }
        int second_mst=1e9;
        for(int i=0; i<tree.size(); i++)
        {
            second_mst=min(second_mst,kruskal(tree[i]));
        }
        if(second_mst==1e9)
        {
            cout<<"No second way"<<endl;
        }
        else
        {
            cout<<second_mst<<endl;
        }
    }
    return 0;
}

/*
Sample Input
4
5 4
1 2 5
3 2 5
4 2 5
5 4 5
5 3
1 2 5
3 2 5
5 4 5
5 5
1 2 5
3 2 5
4 2 5
5 4 5
4 5 6
1 0

Sample Output
Case #1 : No second way
Case #2 : No way
Case #3 : 21
Case #4 : No second way
*/
