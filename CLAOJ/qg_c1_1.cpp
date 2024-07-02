#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <unordered_set>
#include <sstream>
#include <stack>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <cmath>
#include <array>
#include <random>
#define FOR(i, a, b) for (int i = a, _b = b; i <= _b; ++i)
#define FORD(i, a, b) for (int i = a, _b = b; i >= _b; --i)
#define pb push_back
#define fi first
#pragma GCC optimize("O3")
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
#define task "BOXES"
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)

using namespace std;
typedef pair<int, int> ii;
const int maxn = 3e5 + 1;
typedef long long ll;
bool minimize(int &A, int B)
{
    return A > B ? A = B, true : false;
}

// main
ll n, k;
ll c[50][50];
void input()
{
    cin >> n >> k;
    FOR(i, 1, n)
    FOR(j, 1, n)
    cin >> c[i][j];
}
ll dp[MASK(21)];

ll quaylui(ll state)
{
    if (__builtin_popcount(state) == k)
        return 0;
    ll &res = dp[state];
    if (~res) return dp[state];
    res = 1e18;
    FOR(i, 0, n - 1)
    {
        if ((state & MASK(i)) == 0)
            continue;
        FOR(j, 0, n - 1)
        {
            if ((state & MASK(j)) == 0 || i == j)  continue;
            res = min(res, quaylui(state ^ MASK(i)) + c[i + 1][j + 1]);
        }
    }
    return res;
}

void lds_go_goooo()
{
    mset(dp, -1);
    cout << quaylui(MASK(n) - 1);
}

int main()
{
    //	ios_base::sync_with_stdio(false);
    //  cin.tie(0);
      freopen(task".INP", "r", stdin);
     freopen(task".OUT", "w", stdout);
    // int test_case=1; //cin>>test_case;
    // while(test_case--)
    //{
    input(), lds_go_goooo();
    cout << '\n';
    // }
    return 0;
}
