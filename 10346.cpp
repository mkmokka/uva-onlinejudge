/*
10346 - Peter's Smokes
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    long int n,i;
    while(scanf("%ld%ld",&n,&i)==2)
    {
        printf("%ld\n",n+(n-1)/(i-1));
    }
    return 0;
}
/*
Sample Input
4 3
10 3
100 5

Sample Output
5
14
124
*/
