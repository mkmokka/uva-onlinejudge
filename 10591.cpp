/*
10591 - Happy Number
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int test;
    cin>>test;
    for(int loop=1; loop<=test; loop++)
    {
        ll i,j,k,n,sum,num,d;
        cin>>n;
        num =n;
        for(j=1; j!=0; j++)
        {
            sum =0;
            for(i=1; i!=0; i++)
            {
                d = num%10;
                num=num/10;
                sum = sum + d*d;
                if(num==0)
                {
                    num = sum;
                    break;
                }
            }

            if(num<=9)break;
        }
        if(num==1 || num==7) printf("Case #%d: %lld is a Happy number.\n",loop,n);
        else
            printf("Case #%d: %lld is an Unhappy number.\n",loop,n);

    }
    return 0;
}
/*
Sample Input
3
7
4
13

Sample Output
Case #1: 7 is a Happy number.
Case #2: 4 is an Unhappy number.
Case #3: 13 is a Happy number.
*/
