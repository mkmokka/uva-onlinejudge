/*
11547 - Automatic Answer
*/

#include<bits/stdc++.h>
#define MAX 100001
using namespace std;

int main()
{
    int num,a,b,c,d,e,fin,test,i;
    scanf("%d",&test);
    for(i=0; i<test; i++)
    {
        scanf("%d",&num);
        a=(num*567);
        b=a/9;
        c=b+7492;
        d=c*235;
        e=d/47;
        fin=abs(e-498);
        printf("%d\n",(fin%100)/10);
    }
    return 0;
}

/*
Sample Input
2
637
-120

Sample Output
1
3
*/

