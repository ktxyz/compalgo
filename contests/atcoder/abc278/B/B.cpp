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

constexpr int PERIOD = 24 * 60;

bool isConfusing(int t)
{
    int h = t / 60;
    int m = t % 60;

    int nH = h - (h % 10) + (m / 10);
    int nM = (h % 10) * 10 + (m % 10);

    DEBUG_PRINT("%d - %d:%d |  %d:%d\n", t, h, m, nH, nM);

    return (nH >= 0 && nH <= 23 && nM >= 0 && nM <= 59);
}

int main()
{
    int H, M;
    scanf("%d%d", &H, &M);

    int startingMinute = H * 60 + M;
    if (isConfusing(startingMinute))
    {
        printf("%d %d\n", H, M);
        return 0;
    }

    int currMin = (startingMinute + 1) % PERIOD;
    while (currMin != startingMinute)
    {
        if (isConfusing(currMin))
        {
            printf("%d %d\n", currMin / 60, currMin % 60);
            return 0;
        }
        currMin = (currMin + 1) % PERIOD;
    }

    return 0;
}