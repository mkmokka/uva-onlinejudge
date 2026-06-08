/*
389 - Basically Speaking
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    char s[50];
    int n, m;
    while(scanf("%s %d %d", s, &n, &m) == 3)
    {
        int i, l = strlen(s);
        long long dec = 0, j = 1;
        for(i = l-1; i >= 0; i--)
        {
            if(s[i] <= '9')
                dec += (s[i]-'0')*j;
            else
                dec += (s[i]-'A'+10)*j;
            j *= n;
        }
        int ans[60] = {}, idx = -1;
        while(dec > 0)
            ans[++idx] = dec%m, dec /= m;
        if(idx >= 7)
        {
            puts("  ERROR");
            continue;
        }
        if(idx < 0) idx = 0;
        for(i = 6; i > idx; i--)
            printf(" ");
        for(i = idx; i >= 0; i--)
            printf("%c", ans[i] < 10 ? ans[i]+'0' : ans[i]+'A'-10);
        puts("");
    }
    return 0;
}

/*
Sample Input
1111000 2 10
1111000 2 16
2102101 3 10
2102101 3 15
12312 4 2
1A 15 2
ABCD 16 15
03 13 10

Sample Output
120
78
1765
7CA
ERROR
11001
D071
3
*/
