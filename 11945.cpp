/*
11945 - Financial Management
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int main()
{
    int test;
    cin>>test;
    for(int i=0; i<test; i++)
    {
        double n,sum=0,ans;
        int com;
        for(int j=0; j<12; j++)
        {
            cin>>n;
            sum+=n;
        }
        sum/=12.00;

        ll avg = sum;
        ll en = avg%1000;
        avg/=1000;
        ans = sum - ll(sum);

        cout<<i+1<<" $";
        if(avg>0)
        {
            printf("%lld,",avg);
        }
        printf("%.2lf\n",ans+en);

    }
    return 0;
}

/*
Sample Input
1
100.00
489.12
12454.12
1234.10
823.05
109.20
5.27
1542.25
839.18
83.99
1295.01
1.75

Sample Output
1 $1,581.42
*/
