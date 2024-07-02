// Template //
#include <bits/stdc++.h>
#define FOR(i, a, b) for(ll i=a, _b=b; i<=_b; i++)
#define FORD(i, a, b) for(ll i=a, _b=b; i>=_b; i--)
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define mp make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
#define BIT(x, i) ((x>>i)&1)
#define MASK(i) (1LL<<(i))
#define all(a, n) a+1, a+1+n

using namespace std;
typedef int64_t ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
const ll maxn = 5e4+5;
const ll maxL = 1e8+5;
const ll mod = 1e9+7;
const ll inf = 1e18;
const ll base = 37;
const ld eps = 1e-10;

template<class T>
    bool minimize(T &a, T b){
        return a>b ? a=b, true : false;
    }

template<class T>
    bool maximize(T &a, T b){
        return a<b ? a=b, true : false;
    }

ll POW(ll a, ll b)
{
    if (b==0) return 1;
    if (b==1) return a;
    ll tmp=POW(a, b/2) % mod;
    return b%2==0 ? (tmp * tmp)%mod : (((tmp*tmp)%mod)*a)%mod;
}
        // Main Function //
ld n;

void input()
{
    cin>>n;
}

void solve()
{
    cout<<setprecision(5) << fixed << (1-(1/(2*n+3)))/2;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #define task "ATTACK"
//    freopen(task".INP", "r", stdin);
//    freopen(task".OUT", "w", stdout);
    int test_case=1; //cin>>test_case;
    while(test_case--)
    {
        input(), solve();
        cout<<'\n';
    }
    return 0;
}
