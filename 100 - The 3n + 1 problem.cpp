#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
int main()
{
    int i,j;
    while(cin>>i>>j)
    {
        cout<<i<<" "<<j<<" ";
        if(i>j)swap(i,j);
        int max_cycle_len=INT_MIN;
        for(int nbr=i; nbr<=j; nbr++)
        {
            int n=nbr;
            int cycle_len=1;

                while(n!=1)
                {

                    if(n%2==1)n=(n*3)+1;
                    else n=n/2;
                    cycle_len++;
                }
                max_cycle_len=max(max_cycle_len,cycle_len);


            }

            cout<<max_cycle_len<<endl;
        }

    return 0;

}

