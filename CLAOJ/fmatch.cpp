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
long long x[500005],y[500005];
long long d[500005];
vector <long long> k[500005];
int m,n,p;

void input()
{
	cin>>m>>n>>p;
	FOR(i,1,p)
	{
		int u,v;
		cin>>u>>v;
		k[u].pb(v);
	}
}

bool bfs()
{
	queue <int> q;
	FOR(i,1,m)
		if(x[i]==0)
			d[i]=0,q.push(i);
		else
			d[i]=1e9;
	d[0]=1e9;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		if(d[u]<d[0])
			for(int v: k[u])
				if(d[y[v]]>=1e9)
				{
					d[y[v]]=d[u]+1;
					q.push(y[v]);
				}
	}
	
	return (d[0]<1e9);
}

bool dfs(int u)
{
	if(u==0)	return 1;
	for(int v:k[u])
		if(d[y[v]]==d[u]+1)
			if(dfs(y[v]))
			{
				x[u]=v;
				y[v]=u;
				return 1;
			}
	d[u]=1e9;
	return 0;
}

void lds_go_goooo()
{
	mset(x,0);
	mset(y,0);
	int cnt=0;
	while(bfs())
	{
		FOR(i,1,m)
			if(x[i]==0)
				if(dfs(i))
					cnt++;
		/*cout<<"x ";
		FOR(i,0,m)	cout<<x[i]<<' ';
		cout<<endl;
		cout<<"y ";
		FOR(i,0,n)	cout<<y[i]<<' ';
		cout<<endl;
		FOR(i,0,m)
		cout<<d[i]<<' ';
		
		cout<<endl<<endl;*/
	}
	
	cout<<cnt;
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
