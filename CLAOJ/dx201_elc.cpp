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
#define task "BAI3"

using namespace std;
typedef int64_t ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
const ll maxn=250000;
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
struct point{
	double x,y,f;
}p[maxn];

struct NODE{
	int u,v;
	double w;
}node[maxn];

int r[maxn];
double n,ans=0;

double distance(point a,point b)
{
	return (double)sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}

void input()
{
	cin>>n;
	FOR(i,1,n)
	{
		int f;
		cin>>p[i].x>>p[i].y>>p[i].f;
	}
}

int get(int u)
{
	return r[u] ? r[u]=get(r[u]):u;
}

void solve()
{
	int cnt=1;
	FOR(i,1,n)
		FOR(j,i+1,n)
			if(i!=j)
				node[cnt].u=i,node[cnt].v=j,node[cnt].w=distance(p[i],p[j]),cnt++;
	
	sort(node+1,node+cnt,[](NODE a,NODE b)
	{
		return a.w<b.w;
	});
	cnt--;
	FOR(i,1,cnt)
	{
		int u=get(node[i].u);
		int v=get(node[i].v);
			
		if((u!=v)&&(p[u].f==0||p[v].f==0))
		{
			if(p[u].f!=p[v].f)
				p[u].f=p[v].f=1;
			r[u]=v;
			ans+=node[i].w;
		}
	}

	cout<<setprecision(3)<<fixed<<ans;
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
