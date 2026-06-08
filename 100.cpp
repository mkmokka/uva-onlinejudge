/*
100 - The 3n + 1 problem
*/


#include<bits/stdc++.h>
using namespace std;

int func(int a, int b);
int main()
{
    int i,j,result;
    while(scanf("%d %d",&i,&j)!=EOF)
    {
        result = func(i,j);
        printf("%d %d %d\n",i,j,result);
    }
}
int func(int a, int b)
{
    int count=1,val=0,temp;
    if(a>b)
    {
        temp =a;
        a=b;
        b=temp;
    }
    while(a<=b)
    {
        int x=a;
        while(x!=1)
        {
            if(x%2==0)x=x/2;
            else
                x=(3*x)+1;
            count++;
            if(x==1)break;
        }
        if(count>val)
            val=count;
        count=1;
        a++;
    }
    return val;
}

/*
Sample Input
1 10
100 200
201 210
900 1000

Sample Output
1 10 20
100 200 125
201 210 89
900 1000 174
*/

