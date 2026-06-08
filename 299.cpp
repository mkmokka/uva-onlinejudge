/*
299 - Train Swapping
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int input;
    cin>>input;
    while(input--)
    {
        int test;
        cin>>test;
        int ar[test];
        for(int i=0; i<test; i++)
        {
            cin>>ar[i];
        }
        int temp=0,cnt=0;
        for(int i=0; i<test-1; i++)
        {
            for(int j=0; j<test-1; j++)
            {
                if(ar[j]>ar[j+1])
                {
                    temp = ar[j];
                    ar[j]=ar[j+1];
                    ar[j+1]=temp;
                    cnt++;
                }
            }
        }

        printf("Optimal train swapping takes %d swaps.\n",cnt);
    }
    return 0;
}
/*
Sample Input
3
3
1 3 2
4
4 3 2 1
2
2 1

Sample Output
Optimal train swapping takes 1 swaps.
Optimal train swapping takes 6 swaps.
Optimal train swapping takes 1 swaps.
*/
