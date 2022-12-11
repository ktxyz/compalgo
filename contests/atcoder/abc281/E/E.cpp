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

template <class T>
using uset = std::multiset<T>;

constexpr int MAXV = 1e5 + 1;

int N, M, K;
int arr[MAXV];

int main()
{
    uset<int> S;
    scanf("%d%d%d", &N, &M, &K);

    for (int i = 0; i < N; ++i)
    {
        scanf("%d", arr + i);
    }

    for (int i = 0; i < M; ++i)
    {
        S.insert(arr[i]);
    }

    int sum = std::accumulate(S.begin(), std::next(S.begin(), K), 0);
    printf("%d ", sum);

    printf("\n");
    return 0;
}