/*
10347 - Medians
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    double a,b,c;
    for(int i=0; i<1000; i++)
    {
        cin>>a>>b>>c;
        double ans=0,s=0;
        s = (a+b+c)/2.0;
        ans = (4/3.0)*(sqrt(s*(s-a)*(s-b)*(s-c)));
        if(ans>0)
        {
            printf("%.3lf\n",ans);
        }
        else
        {
            ans = -1;
            printf("%.3lf\n",ans);
        }
    }
    return 0;
}
/*
Sample Input
3 3 3
3 3 3

Sample Output
5.196
5.196
*/
