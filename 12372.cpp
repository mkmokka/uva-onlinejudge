/*
12372 - Packing for Holiday
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test,l=20,w=20,h=20;
    int a,b,c,i;
    scanf("%d",&test);
    for(i=1;i<=test;i++){
        scanf("%d %d %d",&a,&b,&c);
        if(a<=l && b<=w && c<=h)
            printf("Case %d: good\n",i);
        else
            printf("Case %d: bad\n",i);

    }
    return 0;
}
/*
Sample Input
2
20 20 20
1 2 21

Sample Output
Case 1: good
Case 2: bad
*/

