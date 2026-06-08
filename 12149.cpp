/*
12149 - Feynman
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int  n;
    while(scanf("%d", &n) != EOF)
    {
        if( n==0)
            break;
        int i, tot=0;
        for (i = 1; i <= n ; ++i)
        {
            tot += i*i ;
        }
        cout<<tot<<endl;
    }
    return 0;
}
/*
Sample Input
2
1
8
0

Sample Output
5
1
204
*/
