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

// End of template//
int n, K, Q;
int d[maxn];
int c[2005][2005];

void input()
{
    cin >> n >> K >> Q;
    FOR(i, 1, n)
    cin >> d[i];
    FOR(i, 0, n)
    FOR(j, 0, n)
    cin >> c[i][j];
}

ll dp[7][22][13][MASK(12)];
//  truck cap n mask
void lds_go_goooo()
{
    mset(dp, 0x3f);
    FOR(i, 1, n)
        dp[1][0][0][0] = 0;

    FOR(i,1,K)
    FOR(cap,0,Q)
        FOR(last,0,n)
                FOR(mask,0,MASK(n)-1)
                {
                    if(cap!=0)
                        minimize(dp[i+1][0][0][mask],dp[i][cap][last][mask]+c[last][0]);
                    FOR(nxt,1,n)
                        if(cap+d[nxt]<=Q&&BIT(mask,(nxt-1))==0)
                            minimize(dp[i][cap+d[nxt]][nxt][mask|MASK(nxt-1)],dp[i][cap][last][mask]+c[last][nxt]);
                   /* if(dp[i][cap][last][mask]<=1e8&&i==K)
                        cout<<dp[i][cap][last][mask]<<endl;*/
                }
    //cout<<dp[1][12][3][MASK(3)-1]<<endl;
    ll ans=1e18;
        FOR(i,1,n)
            FOR(cap,0,Q)
                ans=min(dp[K][cap][i][MASK(n)-1]+c[i][0],ans);
    
    cout<<ans;
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
