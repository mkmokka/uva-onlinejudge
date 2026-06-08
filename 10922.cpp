/*
10922 - 2 the 9s
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int main()
{
    char ab[1005];
    while(scanf("%s",ab)!=EOF)
    {
        if(((int)ab[0]-48)==0)break;
        ll len = strlen(ab);
        ll sum=0,cnt=0,rem,deg =1;
        for(int i=len-1; i>=0; i--)
        {
            sum = sum + (int)ab[i]-48;
        }
        while(sum>9)
        {
            deg++;
            ll b4 = sum;
            sum =0;
            while(b4)
            {
                sum+=b4%10;
                b4/=10;
            }
        }
        if(sum==9)
        {
            cout<<ab<<" is a multiple of 9 and has 9-degree "<<deg<<"."<<endl;
        }
        else
        {
            cout<<ab<<" is not a multiple of 9."<<endl;
        }

    }
    return 0;
}
/*
Sample Input
999999999999999999999
9
9999999999999999999999999999998
0

Sample Output
999999999999999999999 is a multiple of 9 and has 9-degree 3.
9 is a multiple of 9 and has 9-degree 1.
9999999999999999999999999999998 is not a multiple of 9.
*/
