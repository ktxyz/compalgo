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

int main()
{
    umap<int, std::set<int>> userMap;
    int N, Q;
    scanf("%d%d", &N, &Q);

    for (int i = 0; i < Q; ++i)
    {
        int T, A, B;
        scanf("%d %d %d", &T, &A, &B);

        switch (T)
        {
        case 1:
            userMap[A].insert(B);
            break;
        case 2:
            userMap[A].erase(B);
            break;
        case 3:
            printf("%s\n", (userMap[A].find(B) != userMap[A].end() && userMap[B].find(A) != userMap[B].end()) ? "Yes" : "No");
        }
    }

    return 0;
}