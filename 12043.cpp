/*
12043 - Divisors
*/

#include<bits/stdc++.h>
using namespace std;

#define MX 100010
typedef long long LL;
int main()
{
    LL s[MX],d[MX],a,b,k,g,h,t,sqt,test;

    d[1]=1;
    s[1]=1;
    for(LL i=2; i<MX; i++)
    {
        d[i]=2;
        s[i]=1+i;
        sqt=sqrt(i);
        for(LL j=2; j<=sqt; j++)
            if(i%j==0)
            {
                d[i]+=2;
                s[i]+=j+i/j;
            }
        if(sqt*sqt==i)
        {
            d[i]--;
            s[i]-=sqt;
        }
    }
    cin>>test;
    while(test--)
    {
        cin>>a>>b>>k;
        int ar[100005],l=0;
        for(int i=a; i<=b; i++)
        {
            if(i%k==0)
            {
                ar[l++]=i;
            }
        }
        long long fin1=0,fin2=0;
        for(int i=0; i<l; i++)
        {
            fin1 = fin1 + d[ar[i]];
            fin2 = fin2 + s[ar[i]];
        }
        cout<<fin1<<" "<<fin2<<endl;
    }

    return 0;
}

/*
Sample Input
2
5 12 3
1 100 3

Sample Output
13 53
217 3323
*/
