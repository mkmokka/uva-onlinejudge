/*
11854 - Egypt
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int ar[3],a,b,c;
    int sum1=0,sum2=0;
    while(scanf("%d %d %d",&ar[0],&ar[1],&ar[2])==3)
    {
        a = ar[0];
        b= ar[1];
        c=ar[2];
        if(a==0 && b==0 && c==0)break;
        sort(ar,ar+3);
        a = ar[0];
        b= ar[1];
        c=ar[2];
        sum1 = a*a + b*b;
        sum2 = c*c;
        if(sum1==sum2)cout<<"right"<<endl;
        else
            cout<<"wrong"<<endl;
    }
    return 0;
}

/*
Sample Input
6 8 10
25 52 60
5 12 13
0 0 0

Sample Output
right
wrong
right
*/
