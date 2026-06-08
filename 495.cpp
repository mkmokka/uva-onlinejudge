/*
495 - Fibonacci Freeze
*/
#include<bits/stdc++.h>
using namespace std;

int fibonacci(int n)
{
    if(n<=1)
    {
        return n;
    }

    else
        return fibonacci(n-1)+fibonacci(n-2);
}
int main()
{
    int n;
    while(cin>>n)
    {
        printf("The Fibonacci number for %d is %d\n",n,fibonacci(n));
    }
}
/*
Sample Input
5
7
11

Sample Output
The Fibonacci number for 5 is 5
The Fibonacci number for 7 is 13
The Fibonacci number for 11 is 89
*/
