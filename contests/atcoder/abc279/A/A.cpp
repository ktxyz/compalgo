#include <vector>
#include <cstdio>
#include <map>
#include <cstring>
#include <unordered_map>
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

char strs[101];

int main()
{
    scanf("%s", strs);
    int a = 0;
    for (int i = 0; i < strlen(strs); ++i)
        a += (strs[i] == 'v' ? 1 : 2);
    printf("%d", a);
    return 0;
}