/*
12416 - Excessive Space Remover
*/

#include<bits/stdc++.h>
using namespace std;

char s[1000000];
int main()
{
    while(gets(s))
    {
        int cnt=0,max=0,i;
        for(i=0; s[i]; i++)
        {
            if(s[i]==' ')
            {
                cnt++;
            }
            else
            {
            if(cnt>max)
            max = cnt;
                    cnt = 0;
            }
        }
        cnt = 0;
        while(max!=1)
        {
            cnt++;
            max = max/2 + (max-max/2*2);
        }
        cout<<cnt<<endl;
    }
    return 0;
}
/*
Sample Input
A very big joke.
Goodbye!

Sample Output
2
4
*/
