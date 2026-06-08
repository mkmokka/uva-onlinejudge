/*
10701 - Pre, in and post
*/
#include <bits/stdc++.h>
using namespace std;

char a[60], b[60];
int index=0;
void find(int l, int r)
{
    if(l > r) return;
    int i;
    for(i = l; i <= r; i++)
    {
        if(b[i] == a[index])
            break;
    }
    if(i != r+1)
    {
       index++;
        find(l, i -1);
        find(i+1, r);
        putchar(b[i]);
    }
}
int main()
{
    int t, n;
    scanf("%d", &t);
    while(t--)
    {
        cin>>n>>a>>b;
        index = 0;
        find(0, n-1);
        puts("");
    }
    return 0;
}
/*
Sample Input
3
3 xYz Yxz
3 abc cba
6 ABCDEF CBAEDF

Sample Output
Yzx
cba
CBEFDA
*/

