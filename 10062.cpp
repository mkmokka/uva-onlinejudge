/*
10062 - Tell me the frequencies!
*/
#include<bits/stdc++.h>
using namespace std;


bool compare(const pair<int, int>&i, const pair<int, int>&j)
{
    if(i.second==j.second)return i.first>j.first;
    else
    {
        return i.second < j.second;
    }
}

int main()
{
    string str;
    int t=0;
    while(getline(cin, str))
    {
        t++;
        int ar[130]= {0};
        int len = str.length();

        vector< pair<int,int> >v;

        for(int i=0; i<len; i++)
        {
            int d = (int)str[i];
            ar[d]++;
        }
        for(int i=0; i<130; i++)
        {
            if(ar[i]!=0)
            {
                v.push_back(make_pair(i,ar[i]));
            }
        }

        sort(v.begin(),v.end(),compare);

        if(t>1)cout<<endl;
        for(int i=0; i<v.size(); i++)
        {
            cout<<v.at(i).first<<" ";
            cout<<v[i].second<<endl;
        }
        v.erase(v.begin(), v.end());
    }
return 0;
}
/*
Sample Input
AAABBC
122333

Sample Output
67 1
66 2
65 3
49 1
50 2
51 3
*/
