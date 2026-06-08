/*
11450 - Wedding shopping
*/

#include<bits/stdc++.h>
using namespace std;
int N,M,C,k;
int check[210][25];
int cost[25][25];
int test(int money, int g)
{
    if(money<0){
        return -1000000000;}
    if(g==C)
        return M-money;

    if(check[money][g]!=-1)
        return check[money][g];
    int ans=-1;
    for(int i=1; i<=cost[g][0]; i++){
        ans = max(ans, test(money-cost[g][i],g+1));
    }
    return check[money][g]=ans;
}

int main()
{
    cin>>N;
    while(N--)
    {
        cin>>M>>C;
        for(int i=0; i<C; i++)
        {
            cin>>cost[i][0];
            for(int j=1; j<=cost[i][0]; j++)
            {
                cin>>cost[i][j];
            }
        }

        memset(check,-1,sizeof(check));
        int ans = test(M,0);
        if(ans<0)
            cout<<"no solution\n";
        else
            cout<<ans<<endl;
    }
    return 0;
}
/*
Sample Input
3
100 4
3 8 6 4
2 5 10
4 1 3 3 7
4 50 14 23 8
20 3
3 4 6 8
2 5 10
4 1 3 5 5
5 3
3 6 4 8
2 10 6
4 7 3 1 7

Sample Output
75
19
no solution
*/
