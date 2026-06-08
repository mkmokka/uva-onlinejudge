/*
11799 - Horror Dash
*/

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test,i,j,k,a,max,b;
    cin>>test;
    for(k=1; k<=test; k++)
    {
        max =0;
        cin>>a;
        for(i=1; i<=a; i++)
        {
            cin>>b;
            if(b>max)
            {
                max =b;
            }

        }
        printf("Case %d: %d\n",k,max);
    }
    return 0;
}
/*
Sample Input
2
5 9 3 5 2 6
1 2

Sample Output
Case 1: 9
Case 2: 2
*/
