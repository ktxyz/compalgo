#include <vector>
#include <cstdio>
#include <map>
#include <cmath>
#include <unordered_map>
using namespace std;

#ifdef DEBUG
#define DEBUG_PRINT(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#define DEBUG_PRINT(fmt, ...)
#endif

using ll = unsigned long long;
using ull = unsigned long long;
using str = std::string;
template <class T>
using vec = std::vector<T>;
template <class T1, class T2>
using umap = std::unordered_map<T1, T2>;

double f(double A, double B, ll x)
{
    return (A / (sqrt(x + 1)) + B * x);
}

double ternary_search(double A, double B, ll l, ll r)
{
    for (int i = 0; i < 5000; ++i)
    {
        DEBUG_PRINT("l = %llu r = %llu\n", l, r);
        ll m1 = l + (r - l) / 3;
        ll m2 = r - (r - l) / 3;
        DEBUG_PRINT("m1 = %llu m2 =  %llu\n", m1, m2);
        double f1 = f(A, B, m1);
        double f2 = f(A, B, m2);
        if (f1 < f2)
            r = m2;
        else
            l = m1;
    }
    DEBUG_PRINT("CHOSEN %llu\n", l);
    return min(f(A, B, l + 1), min(f(A, B, r), f(A, B, l)));
}

int main()
{
    ll A, B;
    scanf("%lld%lld", &A, &B);

    ll maxVal = 1e18;
    printf("%.10f", ternary_search(A, B, 0, maxVal));

    return 0;
}