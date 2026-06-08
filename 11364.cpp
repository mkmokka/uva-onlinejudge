/*
11364 - Parking
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test,again,n,max,min,i,d;
    scanf("%d",&test);
    for(i=0; i<test; i++)
    {
        scanf("%d",&again);
        max =0;
        min =50000;
        while(again--)
        {
            scanf("%d",&n);
            if(max<n)max=n;
            if(min>n)min=n;
        }
        d=(max-min)*2;
        printf("%d\n",d);

    }
    return 0;
}
/*
Sample Input
2
4
24 13 89 37
6
7 30 41 14 39 42

Sample Output
152
70
*/

