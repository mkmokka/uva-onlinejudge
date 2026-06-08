/*
11877 - The Coco-Cola Store
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,sum,excess;
    while(scanf("%d",&n)==1)
    {
        if(n==0)
            break;
        int cnt = 0;
        while(n>=3)
        {
            n = n-3;
            cnt++;
            n++;
        }
        if(n==2)
        {
            cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
/*
Sample Input
3
10
81
0

Sample Output
1
5
40
*/
