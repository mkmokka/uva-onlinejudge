/*
536 - Tree Recovery
*/

#include <bits/stdc++.h>
using namespace std;

char pre[60], in[60];
int index=0;
void find(int l, int r)
{
    if(l > r) return;
    int i;
    for(i = l; i <= r; i++)
    {
        if(in[i] == pre[index])
            break;
    }
    if(i != r+1)
    {
        index++;
        find(l, i -1);
        find(i+1, r);
        putchar(in[i]);
    }
}
int main()
{
    int t, n;

    while(scanf("%s %s", pre, in)!=EOF)
    {
        index = 0;
        n = strlen(pre);
        find(0, n-1);
        puts("");
    }
    return 0;
}

/*
Sample Input
DBACEGF ABCDEFG
BCAD CBAD

Sample Output
ACBFGED
CDAB
*/

