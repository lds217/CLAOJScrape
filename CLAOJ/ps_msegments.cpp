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
#define task "msegments"

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

vector <int> a;
ll dp[maxn];
vector <pair<int,pair<int,int>>>  adj[maxn];
int n,k;

void input()
{
    cin>>n>>k;
    FOR(i,1,n)
    {
        ll u,v;
        cin>>u>>v;
        adj[u].pb({v,{u,i}});
        adj[v+1].pb({v,{u,i}});
        dp[u]++;
        dp[v+1]--;
    }
}


void lds_go_goooo()
{
    ll ans=0;
    //fi la v, se.fi la u
    vector <int> trace;
    set <pair<int,pair<int,int>>> s;
    FOR(i,1,200005)
    {
        dp[i]+=dp[i-1];
        for(auto x: adj[i])
        {
            int v=x.fi;
            int u=x.se.fi;
            int id=x.se.se;
            if(i==u)
                s.insert({v,{id,-u}});
         
                
        }
         multiset<pair<int,pair<int,int>>>::reverse_iterator rit;
        while(dp[i]>k)
        {
            auto it = s.end();
            it--;
            pair<int,pair<int,int>> tmp=*it;
            if(tmp.fi<i)    s.erase(it);
            else {
              s.erase(it); 
              dp[tmp.fi+1]++;
              dp[i]--;
                ans++;
                trace.pb(tmp.se.fi);
            }
        }
        
        
    }
    //FOR(i,1,3)
    //    cout<<dp[i];
    cout<<ans<<endl;
    for(int i:trace)
        cout<<i<<' ';
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
