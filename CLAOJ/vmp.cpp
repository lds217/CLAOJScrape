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
#define int long long

using namespace std;
typedef long long ll;
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

int n,m,k,s,t;
int val[maxn][6];
vector <ii> a[300005];

void input()
{
	cin>>n>>m>>k>>s>>t;
	while(m--)
	{
		int u,v,w;
		cin>>u>>v>>w;
		a[u].pb({w,v});
		a[v].pb({w,u});
	}
}

int bfs(int st)
{
	int ans=1e18;
	mset(val,0x3f);
	val[st][0]=0;
	queue <pair<ll,ii>> q;
	q.push({0,{s,0}});
	while(!q.empty())
	{
		int u=q.front().se.fi;int c=q.front().se.se;
		int du=q.front().fi;
		q.pop();
	
		if(du!=val[u][c])	continue;
		if(u==t)	ans=min(ans,du);
		for(ii v:a[u])
		{
			if(val[u][c]+v.fi<val[v.se][c])
			{
				val[v.se][c]=val[u][c]+v.fi;
				q.push({val[v.se][c],{v.se,c}});
			}
			if(val[u][c]<val[v.se][c+1]&&c<k)
			{
				val[v.se][c+1]=val[u][c];
				q.push({val[v.se][c+1],{v.se,c+1}});
				
			}
		}
	}
	
	return ans;
}

void lds_go_goooo()
{
	cout<<bfs(s);
}

signed main()
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
