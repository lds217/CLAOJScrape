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
const ll maxn=1e3+2;
const ll mod=26051968;
const ll inf=1e18;


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
int n,m,d[maxn];
vector<ii> k[100000];
int res=0;

void input()
{
	cin>>n>>m;
	FOR(i,1,m)
	{
		int u,v,w;
		cin>>u>>v>>w;
		k[u].push_back({v,w});
	}
}

void dfs(int u)
{
	for(ii v:k[u])
		if(d[u]+v.se>d[v.fi])
		{
			d[v.fi]=d[u]+v.se;
			res=max(res,d[v.fi]);
			dfs(v.fi);
		}
}

void solve()
{
	dfs(1);
	cout<<res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen(task".INP", "r", stdin);
    freopen(task".OUT", "w", stdout);
    ll test_case=1; //cin>>test_case;
    while(test_case--)
    {
        input(), solve();
        cout<<'\n';
    }
    return 0;
}
