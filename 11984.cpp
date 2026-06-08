/*
11984 - A Change in Thermal Unit
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin>>test;
    double c,d,f,diff,ans;
    for(int i=1; i<=test; i++)
    {
        cin>>c>>d;

        diff = (9*c/5+d)*5/9;
        printf("Case %d: %.2lf\n",i,diff);
        ans = 0;

    }
    return 0;
}
/*
Sample Input
2
100 0
0 100

Sample Output
Case 1: 100.00
Case 2: 55.56
*/
