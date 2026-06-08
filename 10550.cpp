/*
10550 - Combination Lock
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int one, two, three, four;

   cin>>one>>two>>three>>four;

    while (one || two || three || four)
    {
        printf("%d\n", 1080 + ((one - two + 40) % 40 + (three - two + 40) % 40 + (three - four + 40) % 40) * 9);

        cin>>one>>two>>three>>four;
    }
}
/*
Sample Input
0 30 0 30
5 35 5 35
0 20 0 20
7 27 7 27
0 10 0 10
9 19 9 19
0 0 0 0

Sample Output
1350
1350
1620
1620
1890
1890
*/
