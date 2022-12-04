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

constexpr int MAXN = 2e5 + 1;
ll add[MAXN];
int timeAdd[MAXN];
int timeSet = -1;
ll baseVal = 0;

int main()
{
    int N, Q;
    scanf("%d", &N);

    for (int i = 0; i < N; ++i)
        scanf("%d", add + i);

    scanf("%d", &Q);
    for (int i = 0; i < Q; ++i)
    {
        int q;
        scanf("%d", &q);

        switch (q)
        {
        case 1:
        {
            scanf("%lld", &baseVal);
            timeSet = i;
        }
        break;
        case 3:
        {
            int k;
            scanf("%d", &k);
            --k;
            DEBUG_PRINT("TIME SET: %lld | TIME ADD = %lld add = %lld\n", timeSet, timeAdd[k], ((timeAdd[k] > timeSet) ? add[k] : 0LL));
            printf("%lld\n", baseVal + ((timeAdd[k] > timeSet) ? add[k] : 0LL));
        }
        break;
        case 2:
        {
            int k, x;
            scanf("%d%d", &k, &x);
            --k;
            if (timeAdd[k] <= timeSet)
            {
                DEBUG_PRINT("RESETING ADD FOR %d\n", k);
                add[k] = 0;
            }
            timeAdd[k] = i;
            DEBUG_PRINT("ADD PRE = %lld\n", add[k]);
            add[k] += x;
            DEBUG_PRINT("ADD POST = %lld\n", add[k]);
        }
        break;
        }
    }

    return 0;
}