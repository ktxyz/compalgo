#include <vector>
#include <cstdio>
#include <map>
#include <iostream>
#include <set>
#include <unordered_map>
#include <algorithm>
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

void addColToSet(int H, int W, vec<string> &S, multiset<string> &SS)
{
    vec<string> Swapped;
    for (int i = 0; i < W; ++i)
    {
        string St = "";
        for (int j = 0; j < H; ++j)
        {
            St += S[j][i];
        }
        SS.insert(St);

#ifdef DEBUG
        std::cout << "NEW SWAPPED: " << St << endl;
#endif
    }
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cout.tie(NULL);
    cin.tie(NULL);
    vec<string> S, T;
    multiset<string> SS, ST;
    int H, W;
    cin >> H >> W;
    for (int i = 0; i < H; ++i)
    {
        string St;
        std::cin >> St;
        S.push_back(St);
    }

    for (int i = 0; i < H; ++i)
    {
        string Tt;
        cin >> Tt;
        T.push_back(Tt);
    }

    addColToSet(H, W, S, SS);
    addColToSet(H, W, T, ST);

    if (SS != ST)
    {
        std::cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
    }

    return 0;
}