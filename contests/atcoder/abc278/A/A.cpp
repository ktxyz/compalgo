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
    vec<int> arr;
    int N;
    int K;
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; ++i)
    {
        int a;
        scanf("%d", &a);
        arr.push_back(a);
    }
    std::reverse(arr.begin(), arr.end());
    for (int i = 0; i < std::min(K, N); ++i)
    {
        arr.pop_back();
    }
    std::reverse(arr.begin(), arr.end());
    while (arr.size() < N)
        arr.push_back(0);
    for (auto i : arr)
        printf("%d ", i);
    printf("\n");
    return 0;
}