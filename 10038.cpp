/*
10038 - Jolly Jumpers
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    while(cin>>test)
    {
        int ar[test+1];
        for(int i=0; i<test; i++)
        {
            cin>>ar[i];
        }
        int check[3001]= {0},flag=0;

        for(int i = 1; i<test; i++)
        {
            int diff = abs(ar[i]-ar[i-1]);
            if(diff<test)
            {
                check[diff]++;
            }
        }
        for(int i=1; i<test; i++)
        {
            if(check[i]==0)
            {
                flag =1;
                break;
            }
        }
        if(flag)cout<<"Not jolly"<<endl;
        else
        {
            cout<<"Jolly"<<endl;
        }
    }
    return 0;
}
/*
Sample Input
4 1 4 2 3
5 1 4 2 -1 6

Sample Output
Jolly
Not jolly
*/


