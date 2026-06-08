/*
11332 - Summing Digits
*/

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ll n,p,fin,t;
    while(scanf("%lld",&n)!=EOF)
    {
        if(n==0)break;
        t=0;
        while(1)
        {

            while(n!=0)
            {
                t=t+(n%10);
                n=n/10;
            }
            if(t/10==0)
                break;
            else
            {
                n=t;
                t=0;
            }
        }
        cout<<t<<endl;
    }
    return 0;
}

/*
Sample Input
2
11
47
1234567892
0

Sample Output
2
2
2
2
*/
