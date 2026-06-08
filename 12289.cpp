/*
12289 - One-Two-Three
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    char ch[10],b;
    int test,i;
    scanf("%d",&test);
    for(i=0; i<test; i++)
    {
        scanf("%s",ch);
        b=strlen(ch);
        if(b==5)
        {
            printf("3\n");
        }
        else
        {
            int cnt=0;
            if (ch[0]=='o')
            {
                cnt++;
            }
            if (ch[1]=='n')
            {
                cnt++;
            }
            if (ch[2]=='e')
            {
                cnt++;
            }
            if(cnt>=2)printf("1\n");
            else
                printf("2\n");
        }
    }
    return 0;
}
/*
Sample Input
3
owe
too
theee

Sample Output
1
2
3
*/
