/*
544 - Heavy Cargo
*/
#include<bits/stdc++.h>
using namespace std;
vector<pair<int,pair<string,string>>>graph;
map<string,string>parent;

string find_parent(string s)
{
    if(parent[s]=="")
    {
        return s;
    }
    else
    {
        return parent[s]=find_parent(parent[s]);
    }
}

int main()
{
    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    int node,edge,cost,tc=0;
    string s1,s2,one,two;
    while(cin>>node>>edge)
    {
        if(node==0 && edge==0)
            break;
        graph.clear();
        parent.clear();
        for(int i=0; i<edge; i++)
        {
            cin>>s1>>s2>>cost;
            graph.push_back(make_pair(cost,make_pair(s1,s2)));
        }
        cin>>s1>>s2;
        int ans=9999999;
        sort(graph.rbegin(),graph.rend());
        for(int i=0; i<edge; i++)
        {
            one = find_parent(graph[i].second.first);
            two = find_parent(graph[i].second.second);
            if(one!=two)
            {
                parent[one]=two;
                if(ans>graph[i].first)
                {
                    ans = graph[i].first;
                }
            }
            if(find_parent(s1)==find_parent(s2))
            {
                break;
            }
        }
        cout<<"Scenario #"<<++tc<<endl;
        cout<<ans<<" tons"<<endl;
        cout<<endl;
    }
    return 0;
}

/*
Sample Input
4 3
Karlsruhe Stuttgart 100
Stuttgart Ulm 80
Ulm Muenchen 120
Karlsruhe Muenchen
5 5
Karlsruhe Stuttgart 100
Stuttgart Ulm 80
Ulm Muenchen 120
Karlsruhe Hamburg 220
Hamburg Muenchen 170
Muenchen Karlsruhe
0 0

Sample Output
Scenario #1
80 tons
Scenario #2
170 tons
*/
