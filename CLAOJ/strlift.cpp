// Template //
#include <bits/stdc++.h>
#define FOR(i, a, b) for(long long i=a, _b=b; i<=_b; i++)
#define FORD(i, a, b) for(ll i=a, _b=b; i>=_b; i--)
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define mp make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
#define MASK(i) (1LL<<(i))
#define BIT(x, i) (((x)>>(i))&1)
#define task ""

using namespace std;
typedef int64_t ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
const ll maxn=1e6+2;
const ll mod=1e9+7;
const ll inf=1e9+7;


bool maximize(ll &A, ll B)
{
    return A<B ? A=B, true : false;
}

bool minimize(ll &A, ll B)
{
    return A>B ? A=B, true : false;
}

ll POW(ll a, ll b)
{
    if (b==0) return 1;
    ll tmp=POW(a, b/2);
    return b%2==0 ? (tmp*tmp)%mod : (tmp*tmp*a) % mod;
}
        // Main Function //

ll n,dp[maxn];

void gen()
{
    dp[1]=dp[2]=1;
    dp[3]=2;
    dp[4]=3;
    dp[5]=5;
    FOR(i,6,maxn)
    {
        dp[i]=(dp[i-1]+dp[i-2]+dp[i-5])%mod;
    }
}

void input()
{
    cin>>n;
    while(n--)
    {

        int a;
        cin>>a;
        cout<<dp[a]<<endl;
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen(task".INP", "r", stdin);
    //freopen(task".OUT", "w", stdout);
    ll test_case=1; //cin>>test_case;
    gen();
    while(test_case--)
    {
        input();
        cout<<'\n';
    }
    return 0;
}
