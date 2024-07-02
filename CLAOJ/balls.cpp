// Template //
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
#include <stdexcept>
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
#include <cassert>
#include <random>

#define FOR(i, a, b) for (ll i = a, _b = b; i <= _b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)


using namespace std;
typedef int64_t ll;
typedef pair<ll, ll> ii;
const ll maxn = 1e5 + 2;
const ll inf = 0x3f3f3f3f3f3f3f3f;


template <class T>
bool maximize(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}



int n, q;
ll v[maxn], c[maxn];
// End of template//

void input()
{
    cin >> n >> q;
    FOR(i, 1, n)
    cin >> v[i];
    FOR(i, 1, n)
    cin >> c[i];
}

ll dp[maxn], dp2[maxn];
ii maxx;
void lds_go_goooo()
{
    while (q--)
    {
        ll a, b;
        cin >> a >> b;
       // mset(dp, -0x3f);
        mset(dp2, -0x3f);
        maxx = {0, 0};
        ll ans = 0;
        FOR(i, 1, n)
        {
            dp[i]=-inf;
            maximize(dp[i], v[i] * b);
            if (dp2[c[i]] != -inf) maximize(dp[i],dp2[c[i]]+v[i]*a);
            if (c[maxx.fi] == c[i])
                maximize(dp[i], dp[maxx.fi] + v[i] * a);
            if (c[maxx.fi] != c[i])
                maximize(dp[i], dp[maxx.fi] + v[i] * b);
            if (c[maxx.se] == c[i])
                maximize(dp[i], dp[maxx.se] + v[i] * a);
            if (c[maxx.se] != c[i])
                maximize(dp[i], dp[maxx.se] + v[i] * b);
            if (dp[i] > dp[maxx.fi] )
            {
                swap(maxx.fi, maxx.se);
                maxx.fi = i;
            }
            else
                if(dp[i] > dp[maxx.se])
                    maxx.se=i;

            maximize(dp2[c[i]], dp[i]);
            maximize(ans, dp[i]);
        }
        cout << ans << '\n';
    }
}
/*
1 -2 3 4 0 -1
1 2 1 2 1 1
5 1
*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

        input();
        lds_go_goooo();


    return 0;
}
