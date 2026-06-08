/*
11172 - Relational Operator
*/

#include<bits/stdc++.h>
using namespace std;

int main()

{
    int test,a,b;
    scanf("%d",&test);
    while(test--){
            scanf("%d %d",&a,&b);
        if(a>b)printf(">\n");
        else if(a<b)printf("<\n");
        else
            printf("=\n");
    }
    return 0;
}

