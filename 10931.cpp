/*
10931 - Parity
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll n;
    while(scanf("%lld",&n)==1)
    {

        if(n==0)break;
        ll rem,sum=0,cnt=0,i=0;
        int ar[1005];
        while(n!=0)
        {
            rem = n%2;
            if(rem==1)cnt++;
            ar[i]=rem;
            n=n/2;
            i++;
        }
        printf("The parity of ");
        for(int j=i-1; j>=0; j--)
        {
            printf("%d",ar[j]);
        }
        printf(" is %lld (mod 2).\n",cnt);

    }
    return 0;
}
/*
Sample Input
1
2
10
21
0

Sample Output
The parity of 1 is 1 (mod 2).
The parity of 10 is 1 (mod 2).
The parity of 1010 is 2 (mod 2).
The parity of 10101 is 3 (mod 2).
*/
