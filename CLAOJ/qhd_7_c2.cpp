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

template <class T> bool minimize(T &a, T b) { if (a > b) { a = b; return true; } return false;}

template <class T> bool maximize(T &a, T b) { if (a < b) { a = b; return true; } return false;}

ll POW(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll tmp = POW(a, b / 2);
    return b % 2 == 0 ? (tmp * tmp) % mod : ((tmp * tmp) % mod * a) % mod;
}

// End of template//
#define int ll
int n,m;
int cnt[maxn];
vector <int> adj[maxn];

void input()
{
    cin>>n>>m;
    FOR(i,1,n-1)
    {
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
}

ll f[maxn]; //nearest infection
ll g[maxn]; // longest not infection
int cur=0;
void dfs(int u,int par, int x)
{
    f[u]=inf,g[u]=0;
    for(int v:adj[u])
    {
        if(v==par)continue;
        dfs(v,u,x);
        g[u]=max(g[u]*1LL,g[v]+1LL);
        f[u]=min(f[u]*1LL,f[v]+1LL);
    }
    if(f[u]+g[u]<=x)   g[u]=-inf; //reset
    else    if(g[u]==x) f[u]=0,g[u]=-inf,cur++;
}

bool check(int x)
{
    cur=0;
    dfs(1,-1,x);
    int cnt=0;
    if(g[1]>=0) cur++;
    return cur<=m;
}

void lds_go_goooo()
{
    int l=0,r=n,ans=n;
    int cnt=0;
    while(r>=l)
    {
        int mid=(l+r)/2;
        if(check(mid))  r=mid-1,ans=mid;
        else    l=mid+1;
        cnt++;
        if(cnt==100)
            break;
    }
    cout<<ans;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #define task "rbtree"
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
