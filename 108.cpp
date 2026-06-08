/*
108 - Maximum Sum
*/


#include<bits/stdc++.h>
using namespace std;
int row,col;
int n;
int M[105][105];
int kadane(int ar[],int &start, int &finish, int n)
{
    int sum=0;
    int maxval=INT_MIN;
    int i;
    int tempstart=0;
    finish =-1;
    for(int i=0; i<n; i++)
    {
        sum+=ar[i];
        if(sum<0)
        {
            sum=0;
            tempstart=i+1;
        }
        else if(sum>maxval)
        {
            maxval = sum ;
            start = tempstart;
            finish=i;
        }
    }
    if(finish!=-1)
        return maxval;

    maxval=ar[0];
    start=finish=0;
    for(int i=0; i<n; i++)
    {
        if(ar[i]>maxval)
        {
            maxval=ar[i];
            start=finish=i;
        }
    }
    return maxval;
}

void findMaxSum()
{
    int maxsum = INT_MIN,endleft,endright,endtop,enddown;
    int left,right,i;
    int temp[row],start,sum,finish;

    for(left=0; left<col; left++)
    {
        memset(temp,0,sizeof(temp));
        for(right=left; right<col; right++)
        {
            for(i=0; i<row; i++)
            {
                temp[i]+=M[i][right];
            }
            sum = kadane(temp,start,finish,row);
            if(sum>maxsum)
            {
                maxsum=sum;
                endleft=left;
                endright=right;
                endtop=start;
                enddown=finish;
            }
        }
    }
    cout<<maxsum<<endl;
}
int main()
{
    cin>>n;
    row=n;
    col=n;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            cin>>M[i][j];
        }
    }
    findMaxSum();
    return 0;
}

/*
Sample Input
4
0 -2 -7 0 9 2 -6 2
-4 1 -4 1 -1
8 0 -2

Sample Output
15
*/

