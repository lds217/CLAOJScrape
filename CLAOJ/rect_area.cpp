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
#define int ll
int n;
struct lds
{
    int x, u, v, val;
};

ii bvoja[4 * 500005];
lds tmp[maxn];
vector<lds> sangph;
set<int>  sy;
vector <int> vy;
int maxx = 0;
void input()
{
    cin >> n;
    FOR(i, 1, n)
    {
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        tmp[i]={x,y,u,v};
        sy.insert(v);
        sy.insert(y);
    }
    vy.pb(-69);
    for(int i:sy)
        vy.pb(i);
    
    FOR(i, 1, n)
    {
        auto [x,y,u,v]=tmp[i];
        y=lower_bound(ALL(vy),y)-vy.begin();
        v=lower_bound(ALL(vy),v)-vy.begin();
        sangph.pb({x, y, v, 1});
        sangph.pb({u, y, v, -1});
        maxx = max({maxx, y, v});
    }
}

void update(int id, int l, int r, int u, int v, int val)
{
    if (v < l || u > r)
        return;
    if (l >= u && r <= v)
    {
        bvoja[id].second += val;
        if (bvoja[id].second != 0)
            bvoja[id].fi =vy[r+1] - vy[l] ;
        else if (l != r)
            bvoja[id].fi = bvoja[id * 2].fi + bvoja[id * 2 + 1].fi;
        else
            bvoja[id].fi = 0;
        return;
    }
    int mid = (l + r) / 2;
    update(2 * id, l, mid, u, v, val);
    update(2 * id + 1, mid + 1, r, u, v, val);

    if (bvoja[id].second != 0)
        bvoja[id].fi = vy[r+1] - vy[l];
    else
        bvoja[id].fi = bvoja[id * 2].fi + bvoja[id * 2 + 1].fi;
}

void lds_go_goooo()
{
    // cout<<maxx;
    // mset(bvoja, 0);
    sort(ALL(sangph), [](lds a, lds b)
         { return a.x < b.x; });
    ll ans = 0;

    FOR(i, 0, sangph.size() - 2)
    {
        update(1, 0, maxx, sangph[i].u, sangph[i].v - 1, sangph[i].val);
        ans += (sangph[i + 1].x - sangph[i].x) * bvoja[1].fi;
    }
    cout << ans;
}

signed main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    //  cout.tie(0);
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
