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
#define task "TIENCO"

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
ll n, m, k, sx, fx;
vector<ii> adj[maxn];
ll d[maxn][2];
ll coins[maxn];
void input()
{
    cin >> n >> m >> k >> sx >> fx;
    FOR(i, 1, k)
    {
        int u, v;
        cin >> u >> v;
        coins[u] = v;
    }
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({w, v});
        adj[v].pb({w, u});
    }
}

void lds_go_goooo()
{
    mset(d, 0x3f);
    
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
    d[sx][0] = 0;
    q.push({0, sx, 0});
    if (coins[sx])
    {
        d[sx][1] = coins[sx];
        q.push({coins[sx], sx, 1});
    }
    while (!q.empty())
    {
        int du = get<0>(q.top());
        int u = get<1>(q.top());
        int used = get<2>(q.top());
        q.pop();
        if (du > d[u][used])
            continue;
        if (u == fx && used==1)
        {
            cout << d[fx][1];
            return;
        }
        for (auto [dv, v] : adj[u])
        {
            if (minimize(d[v][used], d[u][used] + dv))
                q.push({d[v][used], v, used});
            if (used == 0 && coins[v])
                if( minimize(d[v][1], d[u][0] + dv + coins[v]))
                    q.push({d[v][1], v, 1});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen(task ".INP", "r", stdin);
    // freopen(task ".OUT", "w", stdout);
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
