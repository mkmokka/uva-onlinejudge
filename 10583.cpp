/*
10583 - Ubiquitous Religions
*/
#include <bits/stdc++.h>
using namespace std;

int Set[50055];
int nOfReligion;

void Set_Initial(int N)
{
    for (int i = 1; i <= N; ++i)
        Set[i] = i;
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

    if (x != y) {
        Set[x] = y;
        --nOfReligion;
    }
}

int main()
{
    int N, M, Case = 1;
    while (scanf("%d %d", &N, &M) && (N || M)) {

        Set_Initial(N);
        int x, y;
        nOfReligion = N;

        while (M--) {
            scanf("%d%d", &x, &y);
            Union(x, y);
        }
        printf("Case %d: %d\n", Case++, nOfReligion);
    }
    return 0;
}
/*
Sample Input
10 9
1 2
1 3
1 4
1 5
1 6
1 7
1 8
1 9
1 10
10 4
2 3
4 5
4 8
5 8
0 0

Sample Output
Case 1: 1
Case 2: 7
*/
