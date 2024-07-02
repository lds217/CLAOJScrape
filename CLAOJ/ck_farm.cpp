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
#define task "FARM"

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

int n;
vector<ii> k[10000];
ii vs[5005][5005];
int r[100000];
long long sum=0;

struct edge{
	int u,v,w;
};

int maxx=0;

vector<edge> a;

void input()
{
	cin>>n;
	FOR(i,1,n)
	{
		int tmp[100];
		int m;
		cin>>m;
		FOR(j,1,m)
			cin>>tmp[j],maxx=max(maxx,tmp[j]);
		tmp[m+1]=tmp[1];
		FOR(j,1,m)
		{
			int u;
			cin>>u;
			if(vs[tmp[j]][tmp[j+1]].fi==0&&vs[tmp[j+1]][tmp[j]].fi==0)
			{
				vs[tmp[j]][tmp[j+1]]={i,u};
				vs[tmp[j+1]][tmp[j]]={i,u};
			}
			else
			{
				a.pb({i,vs[tmp[j]][tmp[j+1]].fi,vs[tmp[j]][tmp[j+1]].se});
				vs[tmp[j]][tmp[j+1]].fi=vs[tmp[j]][tmp[j+1]].se=0;
				vs[tmp[j+1]][tmp[j]].fi=vs[tmp[j+1]][tmp[j]].se=0;
			}
			
		}
	}
	FOR(i,0,5000)
		FOR(j,0,5000)
			if(vs[i][j].fi!=0&&vs[i][j].se!=0)
			{
				a.pb({vs[i][j].fi,-1,vs[i][j].se});	
				vs[i][j].fi=vs[i][j].se=vs[j][i].se=vs[j][i].fi=0;
			}
}

long long get(long long u)
{
	return r[u]?r[u]=get(r[u]):u;
}

void lds_go_goooo()
{
	mset(r,0);
	
	sort(ALL(a),[](edge a,edge b)
	{
		return a.w<b.w;
	});

//	for(edge i:a)
//		cout<<i.u<<' '<<i.v<<' '<<i.w<<endl;
	
	long long ans1=0;

	for(edge i:a)
	{
		int u=get(i.u);
		int v=get(i.v);
		if(u!=v)
		{
			r[u]=v;
			ans1+=i.w;
		}
	}
	mset(r,0);
	long long ans2=0;
	for(edge i:a)
	{
		if(i.u==-1||i.v==-1)	continue;
		int u=get(i.u);
		int v=get(i.v);
		if(u!=v)
		{
			r[u]=v;
			ans2+=i.w;
		}
	}

	cout<<min(ans1,ans2);
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
        input(), lds_go_goooo();
        cout<<'\n';
    }
    return 0;
}
