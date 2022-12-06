#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#define DEBUG_PRINT(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#define DEBUG_PRINT(fmt, ...)
#endif

using ll = long long;
using ull = unsigned long long;
using str = std::string;
template <class T>
using vec = std::vector<T>;
template <class T1, class T2>
using umap = std::unordered_map<T1, T2>;

// vec<char> crates[10] = {
//     {'Z', 'N'},
//     {'M', 'C', 'D'},
//     {'P'}};
vec<char> crates[10] = {
    {'D', 'L', 'J', 'R', 'V', 'G', 'F'},
    {'T', 'P', 'M', 'B', 'V', 'H', 'J', 'S'},
    {'V', 'H', 'M', 'F', 'D', 'G', 'P', 'C'},
    {'M', 'D', 'P', 'N', 'G', 'Q'},
    {'J', 'L', 'H', 'N', 'F'},
    {'N', 'F', 'V', 'Q', 'D', 'G', 'T', 'Z'},
    {'F', 'D', 'B', 'L'},
    {'M', 'J', 'B', 'S', 'V', 'D', 'N'},
    {'D', 'L', 'G'},
};

int solve1()
{
    std::string tmp, tmp2, tmp3;
    int idx, f, t;

    int a = 0;
    while (scanf("move %d from %d to %d\n", &idx, &f, &t) != EOF)
    {
        for (int i = 0; i < idx; ++i)
        {
            char c = crates[f - 1][crates[f - 1].size() - idx + i];
            crates[t - 1].push_back(c);
        }

        while (idx--)
            crates[f - 1].pop_back();
    }

    for (int i = 0; i < 9; ++i)
        if (crates[i].size())
            printf("%c", crates[i].back());
    printf("\n");

    return a;
}

int solve2()
{
    std::string tmp, tmp2, tmp3;
    int idx, f, t;

    int a = 0;
    while (scanf("move %d from %d to %d\n", &idx, &f, &t) != EOF)
    {
        while (idx--)
        {
            if (crates[f - 1].empty())
                break;
            char c = crates[f - 1].back();
            crates[f - 1].pop_back();
            crates[t - 1].push_back(c);
        }

        for (int i = 0; i < 9; ++i)
            if (crates[i].size())
                printf("%c", crates[i].back());
        printf("\n");
    }

    return a;
}

int main()
{
    std::cout << solve1() << std::endl;
    return 0;
}