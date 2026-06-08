/*
10171 - Meeting Prof. Miguel...
*/

#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
typedef long long ll;

map<char,ll>mapp;

///y for younger and o for older
ll y[30][30],o[30][30];

void y_warshall()
{
    for(int k=1; k<=26; k++)
    {
        for(int i=1; i<=26; i++)
        {
            for(int j=1; j<=26; j++)
            {
                y[i][j]=min(y[i][j],y[i][k]+y[k][j]);
            }
        }
    }
}
void o_warshall()
{
    for(int k=1; k<=26; k++)
    {
        for(int i=1; i<=26; i++)
        {
            for(int j=1; j<=26; j++)
            {
                o[i][j]=min(o[i][j],o[i][k]+o[k][j]);
            }
        }
    }
}

int main()
{
    for(int i='A'; i<='Z'; i++)
    {
        mapp[i]=i-'A'+1;
    }
    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    ll n,c;
    char a,b,u,v;
    while(cin>>n && n!=0)
    {
        for(int i=1; i<=26; i++)
        {
            for(int j=1; j<=26; j++)
            {
                y[i][j]=INF;
                o[i][j]=INF;
            }
        }
        for(int i=1; i<=n; i++)
        {
            cin>>a>>b>>u>>v>>c;
            ll posx = mapp[u];
            ll posy = mapp[v];

            if(a=='Y')
            {
                y[posx][posy]=c;
                if(b=='B')
                    y[posy][posx]=c;
            }
            if(a=='M')
            {
                o[posx][posy]=c;
                if(b=='B')
                    o[posy][posx]=c;
            }
        }
        cin>>u>>v;
        int younger_start=mapp[u];
        int older_start=mapp[v];
        y[younger_start][younger_start]=0;
        o[older_start][older_start]=0;
        y_warshall();
        o_warshall();
        ///now all y[][] will store apsp for younger
        ///and all o[][] will store apsp for older
        ll ans = INF;

        for(int i=1; i<=26; i++)
        {
            ans = min(ans,y[younger_start][i]+o[older_start][i]);
        }
        if(ans==INF)
        {
            cout<<"You will never meet."<<endl;
            continue;
        }
        vector<char>temp;
        for(int i=1; i<=26; i++)
        {
            if(ans==y[younger_start][i]+o[older_start][i])
            {
                temp.push_back(i-1+'A');
            }
        }
        sort(temp.begin(),temp.end());
        cout<<ans;
        for(char it : temp)
        {
            cout<<" "<<it;
        }
        cout<<endl;
    }
    return 0;
}
/*
Sample Input
4
Y U A B 4
Y U C A 1
M U D B 6
M B C D 2
A D
2
Y U A B 10
M U C D 20
A D
0

Sample Output
10 B
You will never meet.
*/
