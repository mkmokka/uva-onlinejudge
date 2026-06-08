/*
10699 - Count the factors
*/

#include<bits/stdc++.h>
using namespace std;
#define N 1000000

int  primesTable[N];
vector<int>v;
int k=0;
void SieveOfEratosthenes()
{

    int i = 2;
    for(; i <= N; ++i)
        primesTable[i] = 1;


    primesTable[0] = primesTable[1] = 0;

    int len = sqrt(N);


    for(i = 2; i <= len; ++i)
    {
        if(primesTable[i])
        {
            for( int k = i << 1; k <= N; k += i )
                primesTable[k] = 0;
        }
    }

    for(i = 0; i <= N; ++i)
    {
        if(primesTable[i])
        {
            v.push_back(i);
            k++;
        }
    }
}

int main()
{
    SieveOfEratosthenes();
    int high;
    while(scanf("%d",&high)!=EOF)
    {
        if(high==0)break;
        int cnt =0;
        for(int l=0; l<k; l++)
        {
            if( high % v[l] == 0)++cnt;
        }
        printf("%d : %d\n",high,cnt);
    }
    return 0;
}
/*
Sample Input
289384
930887
692778
636916
747794
238336
885387
760493
516650
641422
0

Sample Output
289384 : 3
930887 : 2
692778 : 5
636916 : 4
747794 : 3
238336 : 3
885387 : 2
760493 : 2
516650 : 3
641422 : 3
*/
