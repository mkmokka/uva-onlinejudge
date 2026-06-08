/*
10696 - f91
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll return_ans(ll n)
{
    if(n<=100)
        return return_ans(return_ans(n+11));
    else if(n>100)
        return n-10;
}

int main()
{
    ll n,ans;
    while(scanf("%lld",&n)!=EOF)
    {
        if(n==0)break;
        ans = return_ans(n);
        cout<<"f91("<<n<<") = "<<ans<<endl;
    }
    return 0;
}
/*
Sample Input
500
91
0

Sample Output
f91(500) = 490
f91(91) = 91
*/
