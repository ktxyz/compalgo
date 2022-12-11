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

int N, K, D;
int a;
std::set<int> S;

constexpr int MAXV = 1e2 + 1;
int arr[MAXV];
int mR[MAXV];
bool e[MAXV];

int main()
{
    scanf("%d%d%d", &N, &K, &D);

    for (int i = 0; i < N; ++i)
    {
        scanf("%d", arr + i);
    }

    for (int i = 0; i < N; ++i)
    {
        int r = arr[i] % D;
        for (int j = 0; j < K; ++j)
        {
            if (j == r)
            {
                mR[j] = mR[j] + arr[i];
                e[j] = true;
            }
            else
            {
                if (e[j])
                {
                    int nr = (r + j) % D;
                    e[nr] = true;
                    mR[nr] = mR[nr] + arr[i];
                }
            }
        }
    }

    printf("%d\n")
    {
    }

    return 0;
}