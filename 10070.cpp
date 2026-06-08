/*
10070 - Leap Year or Not Leap Year and ...
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    char a[10000];
    int mod_4,mod_100,mod_15,mod_55,mod_400,cnt=0,b,bl,hl;
    while(cin>>a)
    {
        mod_4=mod_100=mod_15=mod_55=mod_400=0;
        int len = strlen(a),b=0,bl=0,hl=0,i;
        for( i=0; i<len; i++)
        {
            mod_4 = (mod_4*10 + (a[i]-48))%4;
            mod_100 = (mod_100*10 + (a[i]-48))%100;
            mod_15 = (mod_15*10 + (a[i]-48))%15;
            mod_55 = (mod_55*10 + (a[i]-48))%55;
            mod_400 = (mod_400*10 + (a[i]-48))%400;
        }
        if(cnt!=0)printf("\n");

        if((mod_4==0 && mod_100!=0)|| mod_400==0)
        {
            cout<<"This is leap year."<<endl;
            b=1;
        }
        if(mod_15==0)
        {
            cout<<"This is huluculu festival year."<<endl;
            hl=1;

        }
        if(mod_55==0 && b)
        {
            cout<<"This is bulukulu festival year."<<endl;
            bl=1;

        }
        if(b!=1 && hl!=1 && bl!=1)
        {
            cout<<"This is an ordinary year."<<endl;

        }
       cnt =1;
    }
return 0;
}
/*
Sample Input
2000
3600
4515
2001

Sample Output
This is leap year.

This is leap year.
This is huluculu festival year.

This is huluculu festival year.

This is an ordinary year.
*/
