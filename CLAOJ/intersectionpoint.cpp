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
#define task "rbtree"
#define int ll
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
struct line
{
    int x, y, u, v;
};

struct vertex
{
    int x, y, val, type;
};

int t[4 * maxn];

void update(int id, int l, int r, int pos, int val)
{
    if (l == r)
    {
        t[id] += val;
        return;
    }

    int mid = (l + r) / 2;
    if (pos <= mid)
        update(2 * id, l, mid, pos, val);
    else
        update(2 * id + 1, mid + 1, r, pos, val);

    t[id] = t[id * 2] + t[id * 2 + 1];
}

ll get(int id, int l, int r, int u, int v)
{
    if (v < l || u > r)
        return 0;
    if (u <= l && v >= r)
        return t[id];
    int mid = (l + r) / 2;
    return get(2 * id, l, mid, u, v) + get(2 * id + 1, mid + 1, r, u, v);
}

vector<vertex> vert;

int n;
set<int> sx, sy;
vector<int> vx, vy;
vector<line> a;

void input()
{
    cin >> n;
    FOR(i, 1, n)
    {
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        y+=1e6+1;
        v+=1e6+1;
        a.pb({x,y,u,v});

        // sx.insert(x);
        // sx.insert(u);
        // sx.insert(v);
        // sx.insert(y);
    }
    // vx.pb(-1e9);
    // for (auto i : sx)
    //     vx.push_back(i);
    for (auto [x, y, u, v] : a)
    {
        // x = lower_bound(ALL(vx), x) - vx.begin();
        // u = lower_bound(ALL(vx), u) - vx.begin();
        // y = lower_bound(ALL(vx), y) - vx.begin();
        // v = lower_bound(ALL(vx), v) - vx.begin();
        if(u<x) swap(u,x);
        if(y>v) swap(y,v);
        if (y == v)
        {
            vert.pb({x, y, 1, 0});
            vert.pb({u+1, y, -1, 0});
        }
        else
            vert.pb({x, y, v, 1});
    }
    sort(ALL(vert), [&](vertex a, vertex b)
    {
        if(a.x==b.x)    return a.type < b.type;
        return a.x<b.x; 
    });

    ll ans = 0;
    for (auto [u, v, val, type] : vert)
    {
        if (type == 1)
            ans += get(1, 1, 4*1000000, v, val);
        else
            update(1, 1, 4*1000000, v, val);
    }
    // FOR(i,1,6*4)
    //     cout<<t[i]<<' ';
    //cout<<endl;
    cout << ans;
}

void lds_go_goooo()
{
}

signed main()
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
