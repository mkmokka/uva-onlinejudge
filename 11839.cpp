/*
11839 - Optical Reader
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,val,a,b,c,d,e,cnt,then,fin=0;
    while(cin>>n)
    {
        if(n==0)
            break;
        for(int i=0; i<n; i++)
        {
            cin>>a>>b>>c>>d>>e;
            cnt=0,then=0,fin=0;
            if(a>=0 && a<=127)
            {
                cnt++;
            }
            else
            {
                ++fin;
            }
            if(b>=0 && b<=127)
            {
                cnt++;
            }
            else
            {
                ++fin;
            }
            if(c>=0 && c<=127)
            {
                cnt++;
            }
            else
            {
                ++fin;
            }
            if(d>=0 && d<=127)
            {
                cnt++;
            }
            else
            {
                ++fin;
            }
            if(e>=0 && e<=127)
            {
                cnt++;
            }
            else
            {
                ++fin;
            }
            if(fin==5 && cnt==0)
                cout<<"*"<<endl;
            else if(cnt==1)
            {
                if(a<=127)
                    cout<<"A"<<endl;
                else if(b<=127)
                    cout<<"B"<<endl;
                else if(c<=127)
                    cout<<"C"<<endl;
                else if(d<=127)
                    cout<<"D"<<endl;
                else if(e<=127)
                    cout<<"E"<<endl;
            }
            else
            {
                cout<<"*"<<endl;
            }
        }
    }
    return 0;
}

/*
Sample Input
3
0 255 255 255 255
255 255 255 255 0
255 255 127 255 255
4
200 200 200 0 200
200 1 200 200 1
1 2 3 4 5
255 5 200 130 205
0

Sample Output
A
E
C
D
*
*
B
*/
