/*
673 - Parentheses Balance
*/


#include<bits/stdc++.h>
using namespace std;

int top,flag,i;
char br[130],ch[130];
void push(void);
void pop(void);

int main()
{
    int test,len,n;
    scanf("%d ",&test);
   while(test--)
    {
        gets(br);
        top=flag=0;
        len=strlen(br);
        for(i=0; i<len; i++)
        {
            if(br[i]=='(' || br[i]=='[')
                {push();}
            else pop();
            if(flag==1)
                break;
        }
        if(top>0)flag=1;
        if(flag==0)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}

void push(void)
{
    ch[top++]=br[i];
    return ;
}


void pop(void)
{
    if(top==0){
    flag=1;
    return;
    }
    else if((br[i]==')'&&ch[--top]!='(') || (br[i]==']'&&ch[--top]!='['))
        flag=1;
    return;

}
/*
Sample Input
3
([])
(([()])))
([()[]()])()

Sample Output
Yes
No
Yes
*/
