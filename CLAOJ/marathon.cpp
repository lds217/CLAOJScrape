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

vector <ii> k[maxn];
int d[maxn];
int h[maxn];
int n,m;
int ans=1e9;

void input()
{
	cin>>n>>m;
	FOR(i,1,n-1)	
	{
		int u,v,w;
		cin>>u>>v>>w;
		k[u].pb({v,w});
		k[v].pb({u,w});
	}
}

void bfs(int x)
{
	mset(h,0x3f);
	mset(d,0x3f);
	queue <ii> q;
	q.push({x,0});
	h[x]=0;
	d[x]=0;
	while(!q.empty())
	{
		int u=q.front().fi;
		int du=q.front().se;
		q.pop();
		if(du!=d[u])	continue;
		for(ii i:k[u])
		{
			int v=i.fi;
			int dv=i.se;
			if(h[u]+1<h[v])
			{
				h[v]=h[u]+1;
				d[v]=dv+d[u];
				q.push({v,d[v]});
			}
			if(d[v]==m)
			{
				ans=min(ans,h[v]);
				return;
			}
		}
	}
}

void lds_go_goooo()	
{
	FOR(i,1,n)
	{
		bfs(i);
	}
	cout<<(ans==1e9?-1:ans);
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
