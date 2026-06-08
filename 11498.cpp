/*
11498 - Division of Nlogonia
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test,i,n,m,x,y;
    while(scanf("%d",&test)==1 && test){
    scanf("%d %d",&n,&m);
   while(test--)
    {
        scanf("%d %d",&x,&y);

        if( x==n || m==y)
        {
            puts("divisa");
        }
        if( x > n && y > m )
        {
            puts("NE");

        }
        if(x>n && y<m)
        {
            puts("SE");
        }
        if(x<n && y<m)
        {
            puts("SO\n");
        }
        if(x<n && y>m)
        {
            puts("NO");
        }
    }
    }
    return 0;
}
/*
Sample Input
3
2 1
10 10
-10 1
0 33
4
-1000 -1000
-1000 -1000
0 0
-2000 -10000
-999 -1001
0

Sample Output
NE
divisa
NO
divisa
NE
SO
SE
*/
