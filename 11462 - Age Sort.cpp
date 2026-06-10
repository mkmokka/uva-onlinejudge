#include <cstdio>

int main()
{
    while (true)
    {
        int n;
        if (scanf("%d", &n) != 1) return 0;

        if (n == 0)
            break;

        int cnt[100] = {0};

        for (int i = 0; i < n; i++)
        {
            int age;
            scanf("%d", &age);
            cnt[age]++;
        }

        bool first = true;
        for (int age = 1; age <= 99; age++)
        {
            while (cnt[age]--)
            {
                if (!first) printf(" ");
                printf("%d", age);
                first = false;
            }
        }
        printf("\n");
    }
    return 0;
}
