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

int n,m;
vector <int> G[maxn];
void input()
{
    cin>>n>>m;
    FOR(i,1,m)
    {
        int u,v;
        cin>>u>>v;
        G[u].pb(v);
        G[v].pb(u);
    }
}

bool joint[maxn];
int num[maxn],low[maxn],timeDFS,bridge;
vector <ii> ans;
void dfs(int u,int par)
{
    int child=0;
    num[u]=low[u]=++timeDFS;
    for(int v:G[u])
    {
        if(v==par) continue;
        if(!num[v])
        {
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]==num[v]) ans.pb({u,v});
            //child++;
            // if(u==par)
            // {
            //     if(child>1)
            //         joint[u]=1;
            // }
            // else
            //     if(low[v]>=num[u])  joint[u]=true;
        }
        else
            low[u]=min(low[u],num[v]);
    }
}



void lds_go_goooo()
{
    FOR(i,1,n)
        if(!num[i])
            dfs(i,i);
    cout<<ans.size()<<endl;
    for(auto [u,v]:ans)
        cout<<u<<' '<<v<<endl;
}

int main()
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
