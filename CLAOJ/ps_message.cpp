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
int low[maxn],num[maxn],timeDfs;
bool deleted[maxn];
vector <int> G[maxn];
int belong[maxn];
stack <int> st;
int n,m;
void input()
{
    cin>>n>>m;
    FOR(i,1,m)
    {
        int u,v;
        cin>>u>>v;
        G[u].pb(v);
    }
}

int scc=0;  
void dfs(int u)
{
    num[u]=low[u]=++timeDfs;
    st.push(u);
    for(int v:G[u])
    {
        if(deleted[v])  continue;
        if(!num[v])
        {
            dfs(v);
            low[u]=min(low[u],low[v]);
        }
        else        
            low[u]=min(low[u],num[v]);
    }

    if(low[u]==num[u])
    {
        scc++;
        int v;
        do{
            v=st.top();
            st.pop();
            belong[v]=scc;
            deleted[v]=true;
        }
        while(v!=u);

    }
}

bool ck[maxn];

void lds_go_goooo()
{
    FOR(i,1,n)
        if(num[i]==0)
            dfs(i);
    
    FOR(i,1,n)
        for(int v:G[i])
            if(belong[i]!=belong[v])
                ck[belong[v]]=1;
    int res=0;
    FOR(i,1,scc)
        if(ck[i]==0)
            res++;
    cout<<res;

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
