/*
10107 - What is the Median?
*/
#include<bits/stdc++.h>

using namespace std;

int data;
vector<int> list1;
int main()
{
    while(scanf("%d",&data)==1)
    {
        list1.push_back(data);
        sort(list1.begin(), list1.end());
        if(list1.size()%2==0)printf("%d\n", (list1[list1.size() / 2] + list1[list1.size() / 2 - 1]) / 2);
        else printf("%d\n", list1[list1.size() / 2]);
    }
return 0;
}
/*
Sample Input
1
3
4
60
70
50
2

Sample Output
1
2
3
3
4
27
4
*/
