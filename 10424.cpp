/*
10424 - Love Calculator
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    char a[30],b[30];
    while(gets(a))
    {
        gets(b);
        int sum1=0,sum2=0,digit=0,rem=0,digit2=0,rem2=0;

        for(int i=0; i<strlen(a); i++)
        {
            if(a[i]>='a' && a[i]<='z')
            {
                sum1 = sum1 + a[i]-97+1;
            }
            else if(a[i]>='A' && a[i]<='Z')
            {
                sum1 = sum1 + a[i]-65+1;
            }
            else
            {
                sum1 = sum1 +0;
            }

        }
        for(int i=0; i<strlen(b); i++)
        {
            if(b[i]>='a' && b[i]<='z')
            {
                sum2 = sum2 + b[i]-97+1;
            }
            else if(b[i]>='A' && b[i]<='Z')
            {
                sum2 = sum2 + b[i]-65+1;
            }
            else
            {
                sum2 = sum2 +0;
            }

        }
        while(1)
        {
            digit =0;
            while(sum1!=0)
            {
                rem = sum1%10;
                digit = digit + rem;
                sum1 = sum1/10;
            }
            if(digit<10)break;
            else
            {
                sum1 = digit;
            }
        }
        while(1)
        {
            digit2 =0;
            while(sum2!=0)
            {
                rem2 = sum2%10;
                digit2 = digit2 + rem2;
                sum2 = sum2/10;
            }
            if(digit2<10)break;
            else
            {
                sum2 = digit2;
            }
        }
        double calculation;
        if(digit>digit2)
        {
            calculation = digit2*100.0/digit;
        }
        else if(digit<=digit2)
        {
            calculation = digit*100.0/digit2;
        }
        printf("%.2lf %%\n",calculation);
    }
    return 0;
}
/*
Sample Input
saima
shanto
Pakistan
India
USA
USSR

Sample Output
71.43 %
100.00 %
100.00 %
*/
