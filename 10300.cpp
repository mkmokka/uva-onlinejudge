/*
10300 - Ecological Premium
*/
#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n,test,a,b,c;
    cin>>n;
    while(n--)
    {
        cin>>test;
        ll sum =0;
        for(ll i=0; i<test; i++)
        {
            cin>>a>>b>>c;
            sum = sum + a*c;
        }
        cout<<sum<<endl;
    }
return 0;
}
/*
Sample Input
3
5
1 1 1
2 2 2
3 3 3
2 3 4
8 9 2
3
9 1 8
6 12 1
8 1 1
3
10 30 40
9 8 5
100 1000 70

Sample Output
38
86
7445
*/
