/*
362 - 18,000 Seconds Remaining
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, test = 0;
    while(scanf("%d", &n) == 1 && n)
    {
        printf("Output for data set %d, %d bytes:\n", ++test, n);
        int sum = 0, cnt = 0;
        int total = 0, x;
        while(scanf("%d", &x) == 1)
        {
            sum += x;
            n -= x;
            cnt++;
            if(cnt == 5)
            {
                printf("   Time remaining: ");
                if(sum == 0)
                    puts("stalled");
                else
                {
                    int tmp = n*5;
                    printf("%d seconds\n", tmp/sum + (tmp%sum != 0));
                }
                sum = 0;
                cnt = 0;
            }
            total++;
            if(n == 0)
                break;
        }
        printf("Total time: %d seconds\n\n", total);
    }
    return 0;
}

/*
Sample Input
100
10
20
20
0
10
0
10
0
10
0
20
200
60
30
100
10
50
5
5
5
5
25
0
0
0
0
0
0
0
0
0
0
1
1
1
1
1
0

Sample Output
Output for data set 1, 100 bytes:
Time remaining: 4 seconds
Time remaining: 5 seconds
Total time: 11 seconds
Output for data set 2, 200 bytes:
Total time: 4 seconds
Output for data set 3, 50 bytes:
Time remaining: 1 seconds
Time remaining: stalled
Time remaining: stalled
Time remaining: 0 seconds
Total time: 20 seconds
*/
