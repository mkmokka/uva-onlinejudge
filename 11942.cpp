/*
11942 - Lumberjack Sequencing
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int ar[100];
    int test,i,max;
    cin>>test;
    cout<<"Lumberjacks:\n";
    while(test--)
    {
        int cnt=0;
        for(i=0; i<10; i++)
        {
            cin>>ar[i];
        }
        if(ar[0]>ar[9])
        {
            for(i=0; i<9; i++)
            {
                if(ar[i]>ar[i+1])
                {
                    cnt ++;
                }
                else
                {
                    cnt==0;
                }
            }
            if(cnt==9)cout<<"Ordered\n";
            else
                cout<<"Unordered\n";
        }
        else if(ar[0]<ar[9])
        {
            for(i=0; i<9; i++)
            {
                if(ar[i]<ar[i+1])
                {
                    cnt++;
                }
                else
                {
                    cnt=0;
                }
            }
            if(cnt==9)cout<<"Ordered\n";
            else
                cout<<"Unordered\n";
        }
        else
            cout<<"Unordered\n";


    }
    return 0;
}

/*
Sample Input
3
13 25 39 40 55 62 68 77 88 95
88 62 77 20 40 10 99 56 45 36
91 78 61 59 54 49 43 33 26 18

Sample Output
Lumberjacks:
Ordered
Unordered
Ordered
*/
