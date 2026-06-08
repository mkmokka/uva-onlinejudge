/*
11280 - Flying to Fredericton
*/

#include<bits/stdc++.h>
using namespace std;

typedef pair<string,int>pp;

unordered_map<string,vector<pp>>graph;
unordered_map<string,long long>dist;
vector<string>serial;
vector<long long>travelcost;
int n;
///here the tricky thing is if we run it reverse then
///for first iteration it will take one no stopover
///then it will take one stopover
///then it will take two stopover and so on......
///In Bellman-Ford algorithm there is a main loop that iterates n-1 times
///(n being the number of nodes).
///At i-th iteration those nodes that their shortest path from
///source to them consists of i intermediate nodes is fixed,
///the same thing we want here.
void bellman_ford()
{
    dist["Calgary"]=0;
    for(int step=1; step<n; step++)
    {
        for(int i=n-2; i>=0; i--)
        {
            string u(serial[i]);
            int sizee = graph[u].size();
            for(int j=0; j<sizee; j++)
            {
                pp temp(graph[u][j]);
                string v(temp.first);
                if(dist[v]>dist[u]+temp.second)
                {
                    dist[v]=dist[u]+temp.second;
                }
            }
        }
        travelcost.push_back(dist["Fredericton"]);
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,tc=0;
    int first=false;
    cin>>t;
    while(t--)
    {
        graph.clear();
        serial.clear();
        travelcost.clear();
        dist.clear();
        string city1,city2;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>city1;
            serial.push_back(city1);
            dist[city1]=INT_MAX;
            graph[city1];
        }
        int m,cost;
        cin>>m;
        for(int i=0; i<m; i++)
        {
            cin>>city1>>city2>>cost;
            graph[city1].push_back(pp(city2,cost));
        }
        bellman_ford();
        cout<<"Scenario #"<<(++tc)<<endl;
        int q,x;
        cin>>q;
        while(q--)
        {
            cin>>x;
            if(x>n-2)x=n-2;
            if(travelcost[x]==INT_MAX)
            {
                cout<<"No satisfactory flights"<<endl;
            }
            else
            {
                cout<<"Total cost of flight(s) is $"<<travelcost[x]<<endl;
            }
        }
        if(t>0)cout<<endl;

    }
    return 0;
}
/*
Sample Input
2

4
Calgary
Winnipeg
Ottawa
Fredericton
6
Calgary Winnipeg 125
Calgary Ottawa 300
Winnipeg Fredericton 325
Winnipeg Ottawa 100
Calgary Fredericton 875
Ottawa Fredericton 175
3 2 1 0

3
Calgary
Montreal
Fredericton
2
Calgary Montreal 300
Montreal Fredericton 325
1 0

Sample Output
Scenario #1
Total cost of flight(s) is $400
Total cost of flight(s) is $450
Total cost of flight(s) is $875

Scenario #2
No satisfactory flights
*/
