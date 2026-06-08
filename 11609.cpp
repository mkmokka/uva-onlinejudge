/*
11609 - Teams
*/

#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007
typedef long long ll;

ll mod_pow(ll a, int b)
{
    int result = 1;
    while(b)
    {
        if(b%2==1)
            result = a*result%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return result;
}
int main()
{
    int test;
    cin>>test;
    for(int i=1; i<=test; i++)
    {
        ll ans=0,then=0,n;
        cin>>n;
        ans = n*pow(2,n-1);
        cout<<"Case #"<<i<<": "<<n*mod_pow(2,n-1)%MOD<<endl;
    }
    return 0;
}

/*
Sample Input
3
1
2
3

Sample Output
Case #1: 1
Case #2: 4
Case #3: 12
*/
