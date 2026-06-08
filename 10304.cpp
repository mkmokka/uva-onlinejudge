/*
10304 - Optimal Binary Search Tree
*/
#include <bits/stdc++.h>
using namespace std;
#define MX 300
int freq[MX];
int s[MX];
int n;
int dp[MX][MX];
int sum(int i, int j);
int optCost(int freq[], int i, int j)
{

    if (j < i)
        return 0;
    if (j == i)
        return 0;


    int &min = dp[i][j];
    if( min != -1 )
        return min;
    min = INT_MAX ;

    for (int r = i; r <= j; ++r)
    {
        int cost = optCost(freq, i, r - 1) +
                   optCost(freq, r + 1, j)+sum(i, r-1)+sum(r+1,j);
        if (cost < min)
            min = cost;
    }
    return min;
}

int sum(int i, int j)
{
    if(i>j)
        return 0;
    return s[j]-s[i-1];
}
int main()
{
    while(scanf("%d",&n)==1)
    {
        memset(s,0,sizeof(s));
        s[0]=0;
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&freq[i]);
            s[i]=s[i-1]+freq[i];
        }
        memset(dp,-1,sizeof (dp));
        cout<<optCost(freq,1,n)<<endl;
    }
return 0;
}
/*
Sample Input
1 5
3 10 10 10
3 5 10 20

Sample Output
0
20
20
*/

