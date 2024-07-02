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
const ll maxn=2*1e4+2;
const ll mod=26051968;
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

long long n,m,s,val[3001];
vector<long long> k[10000];


void dfs(int u)
{
	for(int v:k[u])
		if(val[u]+1<val[v])
		{
			val[v]=val[u]+1;
			dfs(v);
		}
}

void input()
{
	cin>>n>>m>>s;
	while(m--)
	{
		int u,v;
		cin>>u>>v;
		k[u].pb(v);
		k[v].pb(u);
	}
}
void lds_go_goooo()
{
	FOR(i,1,n)	val[i]=inf;
	val[s]=0;
	dfs(s);
	long long ans=0;
	FOR(i,1,n)
		if(val[i]!=inf)
			ans=max(ans,val[i]);
	cout<<(ans!=0?ans+1:ans);
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
