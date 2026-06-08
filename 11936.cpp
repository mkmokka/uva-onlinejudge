/*
11936 - The Lazy Lumberjacks
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    int ar[3];
    cin>>test;
    while(test--)
    {
        cin>>ar[0]>>ar[1]>>ar[2];
        sort(ar,ar+3);
        if((ar[0]+ar[1])>ar[2])
        {
            cout<<"OK"<<endl;
        }
        else
        {
            cout<<"Wrong!!"<<endl;
        }

    }
    return 0;
}
/*
Sample Input
6
1 2 3
3 2 5
3 4 5
6 6 1
3 3 3
7 3 10

Sample Output
Wrong!!
Wrong!!
OK
OK
OK
Wrong!!
*/
