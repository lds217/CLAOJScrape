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
#define FORD(i, a, b) for (ll i = a, _b = b; i >= _b; i--)
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define mp make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)


using namespace std;
typedef int64_t ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
const ll maxn = 2e5 + 100;
const ll mod = 998244353;
const ll inf = 1e18;

const int moveX[] = {0, 0, 1, -1};
const int moveY[] = {-1, 1, 0, 0};

template <class T>
bool minimize(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

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

ll POW(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll tmp = POW(a, b / 2);
    return b % 2 == 0 ? (tmp * tmp) % mod : ((tmp * tmp) % mod * a) % mod;
}

// End of template//

ll n, m;
struct lds
{
    ll c, f, v, type;
};
// 1 have, 2 query
vector<lds> a;

void input()
{
    cin >> n;
    FOR(i, 1, n)
    {
        int w, y, z;
        cin >> w >> y >> z;
        a.pb({w, y, z, 1});
    }
    cin >> m;
    FOR(i, 1, m)
    {
        int w, y, z;
        cin >> w >> y >> z;
        a.pb({w, y, z, 0});
    }
}

ll dp[2000001];

void lds_go_goooo()
{
    mset(dp, -0x3f);
    dp[0]=0;
    sort(ALL(a), [&](lds a, lds b)
         { 
            if(a.f==b.f) return a.type<b.type;
            return a.f < b.f; 
            });
    reverse(ALL(a));
    for (auto [a, b, c, type] : a)
    {
       // cout<<a<<" "<<b<<" "<<c<<endl;
        if (type == 1)
            FORD(i, 100005, a)
                 dp[i] = max(dp[i], dp[i - a] - c);
        else 
            FOR(i, 0, 100005 - a+1)
                dp[i] = max(dp[i], dp[i + a] + c);
    }
    cout << *max_element(dp, dp + 100006);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #define task "cloud"
    freopen(task".INP", "r", stdin);
    freopen(task".OUT", "w", stdout);
    // int sub=1;
    // cin>>sub;
    ll test_case = 1; // cin>>test_case;
    while (test_case--)
    {
        input();
        lds_go_goooo();
        cout << '\n';
    }
    return 0;
}
