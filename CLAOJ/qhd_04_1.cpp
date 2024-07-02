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
const ll maxn = 5e5 + 100;
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
int b,n,m;
int pos[maxn];
int mi[maxn];
int cnt=1;
vector <int> adj[maxn];
int cost[maxn];
void input()
{
    mset(mi,0x3f);
    cin>>b>>n>>m;
    FOR(i,1,b)
    {
        int u;
        cin>>u;
        FOR(j,1,u)
        {
            int v;
            cin>>v;
            pos[cnt++]=i;
            mi[i]=min(mi[i],v);
        }
    }

    FOR(i,1,m)
    {
        cin>>cost[i];
        int u;
        cin>>u;
        FOR(j,1,u)
        {
            int v;
            cin>>v;
            if(v<=n)
                adj[pos[v]].pb(i+n);
            else
                adj[v].pb(i+n);
        }
    }
}
ll dp[MASK(15)];
bool vis[maxn];
int cur=0;
int mask[maxn];

void dfs(int u)
{
    vis[u]=1;
    for(int v:adj[u])
        if(vis[v]==0)
        {
            mask[v]|=MASK(cur);
            dfs(v);
        }
}

void lds_go_goooo()
{
    
    FOR(i,1,b)
    {
        mset(vis,0);
        dfs(i);
        cur++;
    }
    mset(dp,0x3f);
    dp[0]=0;
    FOR(i,0,MASK(b)-1)
    {
        FOR(j,1,b)
            dp[i|MASK(j-1)]=min(dp[i|MASK(j-1)],dp[i]+mi[j]);
        
        FOR(j,1,m)
            dp[i|mask[j+n]]=min(dp[i|mask[j+n]],dp[i]+cost[j]);
    }
    cout<<dp[MASK(b)-1];
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #define task "A007"
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
