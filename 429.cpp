/*
429 - Word Transformation
*/

#include<bits/stdc++.h>
using namespace std;

map<string, int > visited;

void bfs(string start, string end, vector<string> vc)
{
    queue<string>q;
    q.push(start);
    visited[start]=0;

    while(!q.empty() && visited.count(end)==0)
    {
        string top = q.front();
        q.pop();
        for(int i=0; i<vc.size(); i++)
        {
            string now = vc[i];

            if(now.length()==top.length() && visited.count(now)==0)
            {
                int cnt=0;
                for(int j=0; j<now.length(); j++)
                {
                    if(now[j]!=top[j])
                        cnt++;
                }
                if(cnt==1)
                {
                    visited[now] = visited[top]+1;
                    q.push(now);
                }
            }

        }
    }

}

int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--)
    {
        vector<string>vc;
        string first;
        while(cin>>first)
        {
            if(first=="*")
                break;
            vc.push_back(first);
        }
        cin.ignore();
        string fl,start,end;
        while(getline(cin,fl) && fl!="")
        {
            stringstream str(fl);
            str>>start>>end;
            visited.clear();
            bfs(start, end, vc);
            cout<<start<<" "<<end<<" "<<visited[end]<<endl;

        }
        if(tc!=0)cout<<endl;
    }
}
/*
Sample Input
1
dip
lip
mad
map
maple
may
pad
pip
pod
pop
sap
sip
slice
slick
spice
stick
stock
*
spice stock
may pod

Sample Output
spice stock 4
may pod 3
*/
