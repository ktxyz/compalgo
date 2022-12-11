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

int N;
ll T;
ll P;

int constexpr MAXV = 1e5 + 1;
int arr[MAXV];

int main()
{
    scanf("%d %llu", &N, &T);
    for (int i = 0; i < N; ++i)
    {
        scanf("%d", &arr[i]);
        ll l = P;
        P += arr[i];
        if (P >= T)
        {
            printf("%d %llu\n", i + 1, T - l);
            return 0;
        }
    }

    T %= P;
    // printf("WAITING FOR TIME %llu\n", T);
    P = 0;
    for (int i = 0; i < N; ++i)
    {
        ll l = P;
        P += arr[i];
        // printf("%llu %d\n", P, i);
        if (P >= T)
        {
            printf("%d %llu\n", i + 1, (T - l));
            return 0;
        }
    }

    printf("BRAK\n");
    return 0;
}