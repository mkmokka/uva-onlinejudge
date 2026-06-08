/*
12578 - 10:6:2
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    double pi = acos(-1);
    cin>>test;
    for(int i=0; i<test; i++)
    {
        double len,temp=0,radius=0,ans=0,weight=0,area=0;
        cin>>len;
        temp = len/5;
        radius = pi*temp*temp;
        weight = len*0.6;
        area = len*weight;
        ans = (area-radius);
        printf("%.2lf %.2lf\n",radius,ans);
    }
    return 0;
}
/*
Sample Input
1
10

Sample Output
12.57 47.43
*/
