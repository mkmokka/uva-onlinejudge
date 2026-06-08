/*
438 - The Circumference of the Circle
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    double x1,y1,x2,y2,x3,y3;
    double pi = acos(-1.0);
    while(cin>>x1>>y1>>x2>>y2>>x3>>y3)
    {
        double a,b,c,s,L,r,ans;
        a = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        b = sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
        c = sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
        s = (a+b+c)/2;
        L = sqrt(s*(s-a)*(s-b)*(s-c));
        r = (a*b*c)/(4*L*1.0);
        ans = 2*pi*r;
        printf("%.2lf\n",ans);
    }
    return 0;
}
/*
Sample Input
0.0 -0.5 0.5 0.0 0.0 0.5
0.0 0.0 0.0 1.0 1.0 1.0
5.0 5.0 5.0 7.0 4.0 6.0
0.0 0.0 -1.0 7.0 7.0 7.0
50.0 50.0 50.0 70.0 40.0 60.0
0.0 0.0 10.0 0.0 20.0 1.0
0.0 -500000.0 500000.0 0.0 0.0 500000.0

Sample Output
3.14
4.44
6.28
31.42
62.83
632.24
3141592.65
*/
