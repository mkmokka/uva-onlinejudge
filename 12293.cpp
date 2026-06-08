/*
12293 - Box Game
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int main()
{
    ll n;
    while(cin>>n)
    {
        if(n==0)break;
        ll m =1;
        while(m<n)
        {
            m=m*2;
            m++;
        }
        if(m==n)cout<<"Bob"<<endl;
        else
            cout<<"Alice"<<endl;
    }
    return 0;
}
/*
Sample Input
2
3
4
0

Sample Output
Alice
Bob
Alice
*/
