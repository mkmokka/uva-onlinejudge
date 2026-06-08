/*
12036 - Stable Grid
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin>>test;
    for(int i=1; i<=test; i++)
    {
        int n;
        cin>>n;
        int len = n*n;
        int ar[n*n];
        int gg[105]= {0};
        for(int j=0; j<n*n; j++)
        {
            cin>>ar[j];
            gg[ar[j]]++;
        }
        int max = gg[0];
        for(int p=0; p<101; p++)
        {
            if(max<gg[p])
            {
                max = gg[p];
            }
        }
        if(max>n)cout<<"Case "<<i<<": "<<"no"<<endl;
        else
            cout<<"Case "<<i<<": "<<"yes"<<endl;
    }
    return 0;
}

/*
Sample Input
3
4
2 1 1 3
3 1 2 6
2 6 10 3
9 8 7 6
3
1 1 2
1 1 1
2 2 2
3
1 2 3
2 3 1
3 1 2

Sample Output
Case 1: yes
Case 2: no
Case 3: yes
*/
