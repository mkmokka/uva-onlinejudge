/*
12243 - Flowers Flourish from France
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    while(getline(cin,s))
    {
        int cnt = 0,space=0;
        int d = (int)s[0];
        if(s[0]=='*')break;
        for(int i=0; i<s.length(); i++)
        {
            {
                if(s[i]==' ')
                {
                    space++;
                    int temp = (int)s[i+1];
                    if((temp==d) || (temp-32==d)||temp==(d-32)||(temp+32)==d)
                    {
                        cnt++;
                    }
                }

            }
        }
        if(space==cnt)cout<<"Y"<<endl;
        else
            cout<<"N"<<endl;
    }
    return 0;
}
/*
Sample Input
Flowers Flourish from France
Sam Simmonds speaks softly
Peter pIckEd pePPers
truly tautograms triumph
this is NOT a tautogram
*

Sample Output
Y
Y
Y
Y
N
*/
