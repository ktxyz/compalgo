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

std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> pairs;

int solve1()
{
    int a = 0;
    for (auto &p : pairs)
    {
        auto f = p.first;
        auto s = p.second;

        if (f.first <= s.first)
        {
            if (f.second >= s.second)
            {
                ++a;
                continue;
            }
        }

        if (s.first <= f.first)
        {
            if (s.second >= f.second)
            {
                ++a;
                continue;
            }
        }
    }
    return a;
}

int solve2()
{
    int a = 0;
    for (auto &p : pairs)
    {
        auto f = p.first;
        auto s = p.second;

        if (f.first <= s.first)
        {
            if (f.second >= s.first)
            {
                ++a;
                continue;
            }
        }

        if (s.first <= f.first)
        {
            if (s.second >= f.first)
            {
                ++a;
                continue;
            }
        }
    }
    return a;
}

int main()
{
    int a, b, c, d;
    while (scanf("%d-%d,%d-%d", &a, &b, &c, &d) != EOF)
        pairs.push_back({{a, b}, {c, d}});
    printf("%d\n", solve1());
    printf("%d\n", solve2());
    return 0;
}