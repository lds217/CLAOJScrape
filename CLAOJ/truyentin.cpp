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

long long n,m,ut,q;
vector <int> k[200005];
double val[200005];

void input()
{
	cin>>n>>m>>q>>ut;
	
}

void lds_go_goooo()
{
	mset(val,0);
	FOR(i,1,n)	val[i]=inf;
	queue <int> qe;
	bool st[200005];
	while(q--)
	{
		int u;
		cin>>u;
		qe.push(u);	
		val[u]=0;
		st[u]=1;
	}
	while(m--)
	{
		int u,v;
		cin>>u>>v;
		k[u].pb(v);
		k[v].pb(u);
	}

	while(!qe.empty())
	{
		int u=qe.front();
		qe.pop();
		for(int v : k[u])
			if(val[u]+1<val[v]&&st[v]==0)
			{
				val[v]=val[u]+1;
				qe.push(v);
			}
	}
	
	FOR(i,1,n)	
	{
		ll tmp1=0;
		ll tmp2=0;
		if(st[i]==1)
		{
			cout<<0<<' ';
			continue;
		}
		FOR(z,0,n)
		{
			tmp1+=z*ut;
			tmp2+=(z+1)*ut;
			if(tmp1<val[i]&&val[i]<=tmp2)
			{
				cout<<z+1<<' ';
				break;
			}
		}
		
	}
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
