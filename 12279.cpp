/*
12279 - Emoogle Balance
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test,dise=0,kotha=0,cas=1,a,i;
    while(scanf("%d",&test)!=EOF)
    {
        if(test==0)break;
        for(i=0; i<test; i++)
        {
            scanf("%d",&a);

            if(a!=0)
            {
                kotha++;
            }

            else if(a==0)
            {
                dise++;
            }
        }
        printf("Case %d: %d\n",cas,(kotha-dise));

        kotha=0;
        dise=0;
        cas++;
    }
    return 0;
}
/*
Sample Input
5
3 4 0 0 1
4
2 0 0 0
7
1 2 3 4 5 0 0
0

Sample Output
Case 1: 1
Case 2: -2
Case 3: 3
*/

