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
const ll maxn=5*1e4+2;
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

int n;
int vis[maxn];
vector <int> adj[maxn];
void input()
{
	cin>>n;
	FOR(i,1,n)
	{
		int x;
		cin>>x;
		adj[i].pb(x);
	}
}
ll ans;
ll timer=0;
ll track[maxn];
void dfs(int u, int cnt, int type)
{	
	vis[u]=type;
	track[u]=cnt;
	for(int v: adj[u])
		if(!vis[v])
			dfs(v,cnt+1,type);
		else
			if(vis[u]==vis[v])
				ans-=cnt-track[v]+1;
}

void lds_go_goooo()
{
	ans=n;
	FOR(i,1,n)
		if(vis[i]==0)
			dfs(i,1,i);
//	cout<<vis[7];
	cout<<ans;
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
