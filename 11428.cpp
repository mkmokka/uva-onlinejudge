/*
11428 - Cubes
*/


#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i, j;
    int x[10001], y[10001];
    int Ans[10001] = {};
    for(i = 2; i <= 60; i++)
    {
        for(j = i-1; j >= 1; j--)
        {
            if(i*i*i - j*j*j <= 10000 && Ans[i*i*i - j*j*j] == 0)
            {
                Ans[i*i*i - j*j*j] = 1;
                x[i*i*i - j*j*j] = i;
                y[i*i*i - j*j*j] = j;
            }
        }
    }
    int n;
    while(scanf("%d", &n) == 1 && n)
    {
        if(Ans[n])
            printf("%d %d\n", x[n], y[n]);
        else
            puts("No solution");
    }
    return 0;
}
/*
Sample Input
7
37
12
0

Sample Output
2 1
4 3
No solution
*/
