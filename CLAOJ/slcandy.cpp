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
#define task "chiakeo"

using namespace std;
typedef int64_t ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
const ll maxn = 2e7 + 100;
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
vector <ii> a;
ll dp[maxn];
void input()
{
    cin>>n>>m;
    FOR(i,1,m)
    {
        int u,v;
        cin>>u>>v;
        if(u>v)
        {
            if(n<=2e7)
            dp[u]++,dp[n+1]--,dp[1]++,dp[v+1]--;
            a.pb({u,1});
            a.pb({n+1,-1});
            a.pb({1,1});
            a.pb({v+1,-1});
        }
        else
        {
            a.pb({u,1});
            a.pb({v+1,-1});
            if(n<=2e7){
            dp[u]++;
            dp[v+1]--;
            }
        }
    }
}


void lds_go_goooo()
{
    
    if(n<=2e7)
    {
        ll cnt=0,ans=-inf;
        FOR(i,1,n)
        {
            dp[i]+=dp[i-1];
            if(maximize(ans,dp[i]))
                cnt=0;
            if(ans==dp[i])
                cnt++;
        }
       // FOR(i,1,n)
       //     cout<<dp[i]<<' ';
        cout<<endl;
        cout<<ans<<' '<<cnt;
    }
    else
    {
        sort(ALL(a),[&](ii a,ii b)
        {
            if(a.fi==b.fi)
                return a.se>b.se;
            return a.fi<b.fi;
        });
        
        ll cnt=0,ans=-inf;
        ll cur=0;
        a.pb({2e9,1});
        FOR(i,0,a.size()-2)
        {
            cur+=a[i].se;
            if(a[i+1].fi!=a[i].fi)
            {
                if(maximize(ans,cur))
                    cnt=0;
                if(ans==cur)
                    cnt+=a[i+1].fi-a[i].fi;
            }
        }
        cout<<ans<<' '<<cnt;
    }
}

int main()
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
