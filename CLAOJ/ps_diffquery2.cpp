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

const ll ma = 2596;
// End of template//
ll cnt[maxn];
struct query
{
    ll l, r, id, upd;
};
ii updates[maxn];
int anquanhoketrongcay[maxn];
vector<int> val;
vector<query> Q;
int a[maxn];
int n, q;
void input()
{
    cin >> n >> q;
    FOR(i, 1, n)
    {
        cin >> a[i];
        val.pb(a[i]);
    }
}
ll ans1, ans2;
void remove(int x)
{
    cnt[x]--;
    if (cnt[x] == 0)
    {
        ans1--;
        ans2 -= val[x - 1];
    }
}

void add(int x)
{
    cnt[x]++;
    if (cnt[x] == 1)
    {
        ans1++;
        ans2 += val[x - 1];
    }
}

int numupd = 0;
ll L = 0, R = 0;
void lds_go_goooo()
{
    FOR(i, 1, q)
    {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1)
            updates[++numupd] = {l, r};
        if (t == 2)
            Q.pb({l, r, i, numupd});
        if (t == 1)
            val.pb(r);
    }
    sort(ALL(val));
    val.resize(unique(ALL(val)) - val.begin());

    ////////////////////compress//////////////////////////
    for (auto &[u, v] : updates)
        v = lower_bound(ALL(val), v) - val.begin() + 1;

    FOR(i, 1, n)
    a[i] = lower_bound(ALL(val), a[i]) - val.begin() + 1;
    ////////////////////////////////////////////////////////////
    // cout << "a ";
    // FOR(i, 1, n)
    //     cout << a[i] << " \n"[i == n];
    // cout << "updates ";
    // FOR(i, 0, numupd - 1)
    //     cout << updates[i].fi << ' ' << updates[i].se << endl;
    // for (int i : val)
    //     cout << i << ' ';
    // cout << endl;
    // for (auto [l, r, id, upd] : Q)
    //     cout << l << ' ' << r << ' ' << id << ' ' << upd << endl;
    ////////////////////////////////////////////////////////////
    sort(ALL(Q), [&](query a, query b)
         { return make_tuple(a.upd / ma, a.l / ma, a.r) < make_tuple(b.upd / ma, b.l / ma, b.r); });
    ii ans[maxn];
    mset(ans,-1);
    ll currupd = 0;
    for (auto [l, r, id, upd] : Q)
    {
        while (currupd < upd)
        {
            currupd++;
            auto [pos, value] = updates[currupd];
            if (pos >= L && pos <= R)
            {
                remove(a[pos]);
                add(value);
            }
            anquanhoketrongcay[currupd] = a[pos];
            a[pos] = value;
        }
        while (upd < currupd)
        {
            // cout<<"hi";
            auto [pos, value] = updates[currupd];
            value = anquanhoketrongcay[currupd];
            if (pos >= L && pos <= R)
            {
                remove(a[pos]);
                add(value);
            }
            a[pos] = value;
            currupd--;
        }
        while (L < l)
            remove(a[L++]);
        while (L > l)
            add(a[--L]);
        while (R > r)
            remove(a[R--]);
        while (R < r)
            add(a[++R]);
        ans[id] = {ans1, ans2};
    }
    FOR(i, 1, q)
        if(ans[i].fi!=-1&&ans[i].se!=-1)
            cout << ans[i].fi << ' ' << ans[i].se << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#define task "diffquery"
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
/*
 d8b d8b
888888888
`Y88888P'       "Heart"
 `Y888P'      Le Thanh Dat
  `Y8P'
   `Y'

*/
