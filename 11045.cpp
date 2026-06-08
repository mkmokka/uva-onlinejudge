/*
11045 - My T-shirt suits me
*/

#include<bits/stdc++.h>
using namespace std;
/*
 (XXL, XL, L, M , S, or XS)
    1   2  3  4   5     6
*/

const char ss[][4]= {"XXL","XL","L","M","S","XS"};
int graph[30][2];
int used[30];
bool flag;
int n,m,t;
int position(const char *str)
{
    for(int i=0; i<6; i++)
    {
        if(strcmp(ss[i],str)==0)
        {
            return i;
        }
    }
}
void dfs(int idx)
{
    if(flag)
        return;
    if(idx==m)
    {
        flag=true;
        return;
    }
    if(used[graph[idx][0]]>0)
    {
        used[graph[idx][0]]--;
        dfs(idx+1);
        used[graph[idx][0]]++;
    }
    if(used[graph[idx][1]]>0)
    {
        used[graph[idx][1]]--;
        dfs(idx+1);
        used[graph[idx][1]]++;
    }
}

int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=0; i<m; i++)
        {
            char temp[4];
            cin>>temp;
            int idx = position(temp);
            graph[i][0]=idx;
            cin>>temp;
            idx = position(temp);
            graph[i][1]=idx;
        }
        n=n/6;
        ///available T-shirt
        for(int i=0; i<6; i++)
        {
            used[i]=n;
        }
        flag=0;
        dfs(0);
        if(flag)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
/*
Sample Input
3
18 6
L XL
XL L
XXL XL
S XS
M S
M L
6 4
S XL
L S
L XL
L XL
6 1
L M

Sample Output
YES
NO
YES
*/
