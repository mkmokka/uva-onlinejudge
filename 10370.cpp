/*
10370 - Above Average
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin>>test;
    for(int i=0; i<test; i++)
    {
        int siz,sum=0;
        cin>>siz;
        double arr[siz+1];
        for(int j=0; j<siz; j++)
        {
            cin>>arr[j];
        }
        double avg=0,fin=0;
        for(int j=0; j<siz; j++)
        {
            avg = avg + arr[j];
        }
        avg = (avg/siz*1.0);
        int cnt=0;
        for(int k=0; k<siz; k++)
        {
            if(avg<(arr[k]))
            {
                cnt++;
            }
        }
        fin = (cnt*100.0)/siz*1.0;
        printf("%.3lf%%\n",fin);

    }
    return 0;
}
/*
Sample Input
5
5 50 50 70 80 100
7 100 95 90 80 70 60 50
3 70 90 80
3 70 90 81
9 100 99 98 97 96 95 94 93 91

Sample Output
40.000%
57.143%
33.333%
66.667%
55.556%
*/
