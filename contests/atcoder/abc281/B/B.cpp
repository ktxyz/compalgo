#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#define DEBUG_PRINT(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#define DEBUG_PRINT(fmt, ...)
#endif

using ll = long long;
using ull = unsigned long long;

char s[11];

int main()
{
    scanf("%s", s);
    if (strlen(s) != 8 || s[0] < 'A' || s[0] > 'Z' || s[strlen(s) - 1] < 'A' || s[strlen(s) - 1] > 'Z' || s[1] < '1' || s[1] > '9')
    {
        printf("No\n");
        return 0;
    }

    int n = 0;
    for (int i = 2; i < 7; ++i)
    {
        if (s[i] < '0' || s[i] > '9')
        {
            printf("No\n");
            return 0;
        }
    }

    printf("Yes\n");

    return 0;
}