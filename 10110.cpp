/*
10110 - Light, more light
*/
#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
int main()
{
    ull a,ans,second;
    while(scanf("%llu",&a)!=EOF)
    {
        if(a==0)break;
        ans = sqrt(a);
        second = pow(ans,2);
        if(second==a)cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    return 0;
}
/*
Sample Input
3
6241
8191
0

Sample Output
no
yes
no
*/
