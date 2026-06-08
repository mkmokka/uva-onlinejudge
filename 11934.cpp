/*
11934 - Magic Formula
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll a,b,c,d,L,k,i,f;
    while(scanf("%lld %lld %lld %lld %lld",&a,&b,&c,&d,&L)==5)
    {
        k=0;
        if(a==0 && b==0 && c==0 && d==0 && L==0)
        {
            break;
        }
        for(i=0; i<=L; i++)
        {
            f = (i*i*a)+(b*i)+c;
            if(f%d==0)
            {
                k++;
            }
        }
        printf("%lld\n",k);
    }
    return 0;
}

/*
Sample Input
0 0 10 5 100
0 0 10 6 100
1 2 3 4 5
1 2 3 3 5
0 0 0 0 0

Sample Output
101
0
0
4
*/
