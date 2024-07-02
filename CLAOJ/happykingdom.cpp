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
const ll maxn=2*1e5+2;
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

long long r[maxn],n,m,k;
struct node{
	long long u,v,w;
} p[maxn];

long long get(long long u)
{
	return r[u]?r[u]=get(r[u]):u;
}



void input()
{
	cin>>n>>m>>k;
	FOR(i,1,m)
		cin>>p[i].u>>p[i].v>>p[i].w;
	sort(p+1,p+m+1,[](node a,node b)
	{
		return a.w<b.w;	
	});
	long long ans=0;
	FOR(i,1,m)
	{
		int u=get(p[i].u);
		int v=get(p[i].v);
		if(u!=v)
		{
			ans+=p[i].w;
			r[u]=v;
			n--;
		}
		if(n==k)
		    break;
	
	}
	cout<<ans;
}

void solve()
{

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
        input(), solve();
        cout<<'\n';
    }
    return 0;
}
