/*
12527 - Different Digits
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int num,k,temp,flag,i,j,m,n;
    int ans[5005]= {0};
    for(int i=1; i<=5000; i++)
    {
        int frequency[15] = {0};
        num = i ;
        temp = i;
        flag = 0;
        while(num>0)
        {
            k=num%10;
            frequency[k]++;
            num/=10;
        }
        for(j=0; j<=10; j++)
        {
            if(frequency[j]>1)
            {
                flag=1;
            }
        }
        if(flag==1)
        {
            ans[i] = ans[i-1];

        }
        else if(flag==0)
        {
            ans[i] = ans[i-1] + 1;
        }
        flag = 0;
    }
    while(cin>>n>>m)
    {
        cout<<ans[m]-ans[n-1]<<endl;
    }
    return 0;
}

/*
Sample Input
87 104
989 1022
22 25
1234 1234

Sample Output
14
0
3
1
*/
