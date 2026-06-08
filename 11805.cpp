/*
11805 - Bafana Bafana
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    scanf("%d",&test);
    for(int loop=1; loop<=test; loop++)
    {
        int n,k,p,start;
        scanf("%d %d %d",&n,&k,&p);
        start = k;
        for(int i=1; i<=p; i++)
        {
            start = start +1;
            if(start>n)
            {
                start = start%n;
            }
        }
        printf("Case %d: %d\n",loop,start);
    }

    return 0;
}
/*
Sample Input
3
5 2 5
6 3 5
4 1 3

Sample Output
Case 1: 2
Case 2: 2
Case 3: 4
*/
