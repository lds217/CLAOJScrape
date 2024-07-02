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
#define task "qua"

using namespace std;
typedef int64_t ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
const ll maxn = 5e5 + 100;
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
ll n;
#define int ll

ll T[2000005];

void update(int id, int l, int r, int pos, ll val){
    if (l == r){
        T[id] = max(val,T[id]);
        return;
    }
    int mid = (l+r)/2;
    if (pos <= mid) update(id*2, l, mid, pos, val);
    else update(id*2+1, mid+1, r, pos, val);
    T[id] = max(T[id*2], T[id*2+1]);
}
 
ll query(int id, int l, int r, int u, int v){
    if (l > v || r < u) return 0;
    if (l >= u && r <= v) return T[id];
    int m = (l+r)/2;
    return max(query(id*2, l, m, u, v), query(id*2+1, m+1, r, u, v));
}

struct lds{
    ll a,w,id;
};

lds a[maxn];

void input()
{
    cin >> n;
    FOR(i,1,n){
        int u,v;
        cin>>u>>v;
        a[i]={u,v,i};
    }
    sort(a+1,a+n+1,[&](lds a,lds b){
        if(a.a==b.a){return a.id>b.id;}
        return a.a<b.a;
    });
}


ll dp[maxn];

void lds_go_goooo()
{
    ll ans=0;
    FOR(i,1,n)
    {
        ll t=query(1,1,n,1,a[i].id-1)+a[i].w;
        ans=max(t,ans);
        update(1,1,n,a[i].id,t);
    }
    cout<<ans;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
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
