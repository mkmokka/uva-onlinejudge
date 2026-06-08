/*
12459 - Bees' ancestors
*/

#include<bits/stdc++.h>
using namespace std;


typedef long long ll;

ll fib(ll n)
{
    ll a = 0, b = 1, c, i;
    if( n == 0)
        return a;
    for (i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main ()
{
    ll n;
    while(cin>>n)
    {
        if(n==0)break;
        cout<<fib(n+1)<<endl;

    }
    return 0;
}

/*
Sample Input
1
2
3
0

Sample Output
1
2
3
*/
