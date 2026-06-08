/*
10341 - Solve It
*/

#include<bits/stdc++.h>
using namespace std;

#define EXP 1e-7

int p,q,r,s,t,u;
double f(double x)
{
    return p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
}
double ans()
{
    double low = 0,high=1;
    while(low + EXP<high)
    {
        double x = (low+high)/2;
        if(f(low)*f(x)<=0)
        {
            high = x;
        }
        else
        {
            low = x;
        }

    }
    return (low+high)/2;
}
int main()
{
    while(scanf("%d %d %d %d %d %d",&p,&q,&r,&s,&t,&u)!=EOF)
    {
        if(f(0)*f(1)>0)
        {
            printf("No solution\n");
        }
        else
        {
            printf("%.4lf\n",ans());
        }
    }
    return 0;
}

/*
Sample Input
0 0 0 0 -2 1
1 0 0 0 -1 2
1 -1 1 -1 -1 1

Sample Output
0.7071
No solution
0.7554
*/
