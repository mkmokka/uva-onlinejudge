/*
11530 - SMS Typing
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin>>test;
    for(int k=1; k<=test+1; k++)
    {
        string s;
        getline(cin,s);
        int len=0,cnt=0;
        for(len = 0; s[len] != '\0'; ++len);
        for(int j=0; j<len; j++)
        {
            if(s[j]=='a')cnt+=1;
            else if(s[j]=='b')cnt+=2;
            else if(s[j]=='c')cnt+=3;

            else if(s[j]=='d')cnt+=1;
            else if(s[j]=='e')cnt+=2;
            else if(s[j]=='f')cnt+=3;

            else if(s[j]=='g')cnt+=1;
            else if(s[j]=='h')cnt+=2;
            else if(s[j]=='i')cnt+=3;

            else if(s[j]=='j')cnt+=1;
            else if(s[j]=='k')cnt+=2;
            else if(s[j]=='l')cnt+=3;

            else if(s[j]=='m')cnt+=1;
            else if(s[j]=='n')cnt+=2;
            else if(s[j]=='o')cnt+=3;

            else if(s[j]=='p')cnt+=1;
            else if(s[j]=='q')cnt+=2;
            else if(s[j]=='r')cnt+=3;
            else if(s[j]=='s')cnt+=4;

            else if(s[j]=='t')cnt+=1;
            else if(s[j]=='u')cnt+=2;
            else if(s[j]=='v')cnt+=3;

            else if(s[j]=='w')cnt+=1;
            else if(s[j]=='x')cnt+=2;
            else if(s[j]=='y')cnt+=3;
            else if(s[j]=='z')cnt+=4;

            else if(s[j]==' ')cnt+=1;

        }
        if(cnt==0)
        {
            continue;
        }
        else
        {
            printf("Case #%d: %d\n",k-1,cnt);
        }
    }
    return 0;
}
/*
Sample Input
2
welcome to ulab
good luck and have fun

Sample Output
Case #1: 29
Case #2: 41
*/
