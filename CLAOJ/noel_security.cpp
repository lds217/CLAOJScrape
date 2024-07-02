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
#define int ll

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
int n,p,q,s;
struct Edge{
    int u,v,w;
}edge[maxn];
vector <ii> adj[maxn];
ll timer=0;
ll fin[maxn],fout[maxn];
ll f[maxn],g[maxn],h[maxn];
ll Par[maxn][25],Min[maxn][25];
void input()
{
    cin>>n>>p>>q>>s;
    FOR(i,1,n-1)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
        edge[i]={u,v,w};
    }
    FOR(i,0,n+5)  
        g[i]=inf;
    FOR(i,1,p)
    {
        int x;
        cin>>x;
        g[x]=0;
    }
}

void dfs(int u,int par)
{
    Par[u][0]=par;
    fin[u]=++timer;
    for(auto[v,w]:adj[u])
    {
        if(v==par) continue;
        f[v]=f[u]+w;
        h[v]=h[u]+1;
        dfs(v,u);
        g[u]=min(g[v]+w,g[u]);
    }
    for(auto[v,w]:adj[u])
    {
        if(v==par)  continue;
        Min[v][0]=g[u]-f[u];
    }
    fout[u]=timer;
}

bool a_con_b(int a,int b)
{
    return fin[b]<=fin[a]&&fout[a]<=fout[b];
}

int get(int u,int v)
{
    ll len=h[u]-h[v];
    ll ans=inf;
    FORD(i,19,0)
        if(BIT(len,i))
        {
            ans=min(Min[u][i],ans);
            u=Par[u][i];
        }
    return ans;
}

void lds_go_goooo()
{
    dfs(s,s);
    FOR(i,1,19)
        FOR(j,1,n)
        {
            Par[j][i]=Par[Par[j][i-1]][i-1];
            Min[j][i]=min(Min[j][i-1],Min[Par[j][i-1]][i-1]);
        }
    while(q--)
    {
        int i,x;
        cin>>i>>x;
        auto [u,v,w]= edge[i];
        if(Par[u][0]==v)
            swap(u,v);
        if(!a_con_b(x,v))
            cout<<"failed";
        else{
            ll ans=inf;
            ans=min(g[x],f[x]+get(x,v));
            if(ans!=inf)
                cout<<ans;
            else
                cout<<"miss";
        }
        cout<<'\n';
    }
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
