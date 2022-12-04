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

constexpr int MAXS = 301;

int integer[MAXS][MAXS];
int cnt[MAXS][MAXS][MAXS];

int main()
{
    int H, W, N, h, w;
    scanf("%d%d%d%d%d", &H, &W, &N, &h, &w);

    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            scanf("%d", integer[i] + j);

    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            cnt[i][j][integer[i][j]] += 1;
            for (int k = 0; k < MAXS; ++k)
            {
                if (i > 0)
                    cnt[i][j][k] += cnt[i - 1][j][k];
                if (j > 0)
                    cnt[i][j][k] += cnt[i][j - 1][k];

                if (i > 0 && j > 0)
                    cnt[i][j][k] -= cnt[i - 1][j - 1][k];
            }
        }
    }

    for (int i = 0; i <= (H - h); ++i)
    {
        for (int j = 0; j <= (W - w); ++j)
        {
            int diff = 0;
            for (int k = 1; k <= MAXS; ++k)
            {
                int i_cnt = cnt[i + h - 1][j + w - 1][k];
                int l = 0, r = 0, c = 0;

                if (i > 0)
                {
                    l = cnt[i - 1][j + w - 1][k];
                }

                if (j > 0)
                {
                    r = cnt[i + h - 1][j - 1][k];
                }

                if (i > 0 && j > 0)
                    c = cnt[i - 1][j - 1][k];

                i_cnt = i_cnt - l - r + c;

                if (cnt[H - 1][W - 1][k] - i_cnt > 0)
                {
                    diff++;
                }
            }
            printf("%d ", diff);
        }
        printf("\n");
    }
    return 0;
}