/*
12342 - Tax Calculator
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    double n,tax=0;
    long long int ans,test,i=1;
    cin>>test;
    while(test--)
    {

        cin>>n;
        if(n<=180000.0)tax = 0.0;
        else if(n>180000.0 && n<=480000.0)
        {
            tax = (n-180000.0)*0.1;
        }
        else if(n>480000.0&&n<=880000.0)
        {
            tax = ((n-480000.0)*0.15)+30000.0;
        }
        else if(n>880000.0 && n<=1180000.0)
        {
            tax = (n-880000.0)*0.2+90000.0;
        }
        else if(n>1180000.0)
        {
            tax = (n-1180000.0)*0.25+150000.0;
        }
        if(tax>0.0 &&tax<2000.0)tax = 2000.0;
        ans = ceil(tax);

        cout<<"Case "<<i++<<": "<<ans<<endl;

    }
    return 0;
}

/*
Sample Input
3
180001
12345
615000

Sample Output
Case 1: 2000
Case 2: 0
Case 3: 50250
*/
