/*
12626 - I ❤ Pizza
*/

#include<bits/stdc++.h>
using namespace std;

int main()

{
    string str;
    int test;
    cin>>test;
    for(int j=0; j<test; j++)
    {
        cin>>str;
        int len = str.size();
        int qq[10]= {0};
        for(int i=0; i<len; i++)
        {
            if(str[i]=='M')qq[0]++;
            else if(str[i]=='A')qq[1]++;
            else if(str[i]=='R')qq[2]++;
            else if(str[i]=='G')qq[3]++;
            else if(str[i]=='I')qq[4]++;
            else if(str[i]=='T')qq[5]++;
        }
        qq[1]=qq[1]/3;
        qq[2]=qq[2]/2;
        sort(qq,qq+6);
        cout<<qq[0]<<endl;

    }
    return 0;
}
/*
Sample Input
5
MARGARITA
AAAAAAMMRRTITIGGRRRRRRRR
AMARGITA
BOLOGNESACAPRICHOSATOMATERA
ABCDEFGHIJKLMNOPQRSTUVWXYZ

Sample Output
1
2
0
1
0
*/
