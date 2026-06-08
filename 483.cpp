/*
483 - Word Scramble
*/

#include<bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    while(getline(cin,str))
    {
        int start =0;
        int end;
        for(int i=0; i<=str.size(); i++)
        {
            if(str[i]==' ' || i==str.size())
            {
                end = i-1;

                while(start<end)
                {
                    swap(str[start],str[end]);
                    start++;
                    end--;
                }
                start = i+1;
            }
        }
        cout<<str<<endl;
    }
    return 0;
}

/*
Sample Input
I love you.
You love me.
We're a happy family.

Sample Output
I evol .uoy
uoY evol .em
er'eW a yppah .ylimaf
*/
