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
#define task "BOBASO"

using namespace std;
typedef int64_t ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
const ll maxn = 2e6 + 100;
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
int n;
ll a[maxn];
void input()
{
    cin >> n;
    FOR(i, 1, n)
    cin >> a[i];
}
int tree[maxn];

void build(int id, int l, int r)
{
    if (l == r)
    {
        tree[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    tree[id] = max(tree[id * 2], tree[id * 2 + 1]);
}

int getmax(int id, int l, int r, int u, int v)
{
    if (v < l || u > r)
        return -1e9;
    if (u <= l && v >= r)
        return tree[id];
    int mid = (l + r) / 2;
    return max(getmax(id * 2, l, mid, u, v), getmax(id * 2 + 1, mid + 1, r, u, v));
}
ll dpma[maxn][2], dpmi[maxn][2];
void lds_go_goooo()
{
    if (n <= 100)
    {
        ll ans = -inf;
        FOR(i, 1, n)
        FOR(j, i + 1, n)
        FOR(k, j + 1, n)
        maximize(ans, 2 * a[j] + abs(a[i] - a[k]));
        cout << ans;
    }
    else
    {
        mset(dpma,-0x3f);
        mset(dpmi,0x3f);

        FOR(i,1,n)
        {
            dpma[i][0]=max(dpma[i-1][0],a[i]);
            dpmi[i][0]=min(dpmi[i-1][0],a[i]);
        }

        FORD(i,n,1)
        {
            dpma[i][1]=max(dpma[i+1][1],a[i]);
            dpmi[i][1]=min(dpmi[i+1][1],a[i]);
        }

        ll ans=-inf;
        FOR(i,2,n-1)
        {
            ans=max({ans,2*a[i]+max(abs(dpma[i-1][0]-dpmi[i+1][1]),abs(dpma[i+1][1]-dpmi[i-1][0]))});
        }
        cout<<ans;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen(task".INP", "r", stdin);
    // freopen(task".OUT", "w", stdout);
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
