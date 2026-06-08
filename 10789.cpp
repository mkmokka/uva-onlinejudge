/*
10789 - Prime Frequency
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin>>test;
    for(int loop=1; loop<=test; loop++)
    {
        char aa[2020];
        cin>>aa;
        int freq[200]= {0};
        int f=0,p=0,i,j,k;
        for(int j=0; j<strlen(aa); j++)
        {
            freq[aa[j]]++;
        }
        printf("Case %d: ",loop);
        for( k=48; k<=122; k++)
        {
            if(freq[k]!=0)
            {
                for(i=2; i<=sqrt(freq[k]); i++)
                {
                    f=0;
                    if(freq[k]%i==0)
                    {
                        break;
                    }
                    else
                    {
                        f=1;
                    }
                }
                if(f==1 || freq[k]==2 || freq[k]==3)
                {
                    printf("%c",k);
                    p=1;
                }
            }
        }
        if(p==1)printf("\n");
        if(p==0)printf("empty\n");
    }
    return 0;
}
/*
Sample Input
3
ABCC
AABBBBDDDDD
ABCDFFFF

Sample Output
Case 1: C
Case 2: AD
Case 3: empty
*/
