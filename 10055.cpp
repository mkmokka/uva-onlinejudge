/*
10055 - Hashmat the Brave Warrior
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int a, b;
    while(scanf("%lld %lld", &a, &b) != EOF)
    {
        if(a > b)
            printf("%lld\n", a - b);
        else
            printf("%lld\n", b - a);
    }
    return 0;
}

/*
Sample Input
10 12
10 14
100 200

Sample Output
2
4
100
*/
