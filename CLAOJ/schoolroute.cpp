// Template //
#include <bits/stdc++.h>
#define FOR(i, a, b) for(ll i=a, _b=b; i<=_b; i++)
#define FORD(i, a, b) for(ll i=a, _b=b; i>=_b; i--)
#define pb push_back
#define ALL(a) a.begin(), a.end()
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
const ll maxn=4*1e5+2;
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



ll n,m;

vector <ll> k[maxn];


struct edge{
	ll w,u,v;
}  a[maxn];

void input()
{
	cin>>n>>m;
	FOR(i,1,m)
	{
		ll u,v,w;
		cin>>u>>v>>w;
		k[u].pb(i);
		k[v].pb(i);
		a[i]={w,u,v};
	}
	
}

ll d[maxn];
ll r[maxn];
void bfs(ll s)
{
	mset(d,0x3f);
	queue<ii> q;
	q.push({0,s});
	
	d[s]=0;
	while(!q.empty())
	{
		ll u=q.front().se;
		ll du=q.front().fi;
		q.pop();
		if(d[u]!=du)	continue;
		for(ll i:k[u])
		{
			ll v;
			if(u==a[i].u) v=a[i].v;
			else	v=a[i].u;
			if(d[v]>d[u]+a[i].w)
			{
				d[v]=d[u]+a[i].w;
				q.push({d[v],v});
				r[v]=i;
			}
			else
				if(d[v]==d[u]+a[i].w&&a[r[v]].w>a[i].w)
					r[v]=i;
		}
	}
}


void lds_go_goooo()
{

	bfs(1);
	cout<<n-1<<endl;
	FOR(i,1,m)
		if(r[i])
			cout<<r[i]<<' ';
		
	
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
