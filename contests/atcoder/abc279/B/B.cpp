#include <vector>
#include <cstdio>
#include <string>
#include <map>
#include <iostream>
#include <unordered_map>
using namespace std;

#define endl '\n'
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
    ios_base::sync_with_stdio(NULL);
    cout.tie(NULL);
    cin.tie(NULL);

    string S, T;
    std::cin >> S >> T;

    std::cout << (S.find(T, 0) != string::npos ? "Yes" : "No") << endl;

    return 0;
}