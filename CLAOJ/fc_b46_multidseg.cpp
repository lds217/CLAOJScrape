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
#define MASK(i) (1LL<<(i))
#define BIT(x, i) (((x)>>(i))&1)
#define task "SUADUONG"

using namespace std;
typedef int64_t ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
const ll maxn=1e5+2;
const ll mod=1e9+7;
const ll inf=1e18;

const int moveX[]={0,0,1,-1};
const int moveY[]={-1,1,0,0};

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

//main

int n,k;
vector <int> divs[maxn];
long long dp[maxn][55];
void input()
{
	cin>>n>>k;
}

void pre()
{
	FOR(i,1,n)
		for(int j=i;j<=n;j+=i)
			divs[j].pb(i);
	mset(dp,0);
	FOR(i,1,n)	dp[i][1]=1;
	FOR(i,1,k)	dp[1][i]=1;
	
	long long ans=1;
	FOR(i,2,n)
	{
		for(int d: divs[i])
			FOR(j,2,k)
				dp[i][j]=(dp[i][j]+dp[d][j-1])%mod;
		ans=(ans+dp[i][k])	%mod;
	}
	cout<<ans;
				
}

void lds_go_goooo()
{
	pre();
}

int main()
{
 	ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen(task".INP", "r", stdin);
    //freopen(task".OUT", "w", stdout);
    ll test_case=1; //cin>>test_case;
    while(test_case--)
    {
        input(), lds_go_goooo();
        cout<<'\n';
    }
    return 0;
}