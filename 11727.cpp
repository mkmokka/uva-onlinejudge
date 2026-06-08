/*
11727 - Cost Cutting
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,test,i;
    scanf("%d",&test);
    for(i=1; i<=test; i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        if((a>b && a<c)||(a<b && a>c))printf("Case %d: %d\n",i,a);
        else if((b>c && b<a)||(b<c && b>a))printf("Case %d: %d\n",i,b);
        else if((c>a && c<b)||(c<a && c>b))printf("Case %d: %d\n",i,c);
    }
    return 0;
}
/*
Sample Input
3
1000 2000 3000
3000 2500 1500
1500 1200 1800

Sample Output
Case 1: 2000
Case 2: 2500
Case 3: 1500
*/
