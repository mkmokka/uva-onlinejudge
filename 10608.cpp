/*
10608 - Friends
*/

#include <bits/stdc++.h>
using namespace std;

int Set[30010];
int Num[30010];

void make_SET(int N)
{
    for (int i = 1; i <= N; ++i)
    {
        Set[i] = i;
        Num[i] = 1;
    }
}
int FindRoot(int x)
{
    if (x == Set[x])
        return x;
    return Set[x] = FindRoot(Set[x]);
}
void Union(int x, int y)
{
    x = FindRoot(x);
    y = FindRoot(y);

    if (x != y)
    {
        Set[x] = y;
        Num[y] += Num[x];
    }
}
int FindLargest(int N)
{
    int Max = 0;
    for (int i = 1; i <= N; ++i)
        if (Num[i] > Max)
            Max = Num[i];
    return Max;
}

int main()
{
    int Case, N, M, A, B;
    scanf("%d", &Case);
    while (Case--)
    {
        scanf("%d %d", &N, &M);
        make_SET(N);
        while (M--)
        {
            scanf("%d %d", &A, &B);
            Union(A, B);
        }
        printf("%d\n", FindLargest(N));
    }
    return 0;
}
/*
Sample Input
2
3 2
1 2
2 3
10 12
1 2
3 1
3 4
5 4
3 5
4 6
5 2
2 1
7 1
1 2
9 10
8 9

Sample Output
3
7
*/
