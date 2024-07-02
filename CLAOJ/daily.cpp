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
const ll maxn=2*1e3+2;
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

vector <int> adj[maxn];
ll val[2][maxn];
bool vis0[maxn];
bool vis1[maxn];
int n,m;
int x,y;
queue <ii> q;
void input()
{
	cin>>n>>m;
	cin>>x>>y;
	q.push({0,x});
	q.push({1 ,y}); 
	FOR(i,1,m)
	{
		int u,v;
		cin>>u>>v;
		adj[u].pb(v);
	}
}

int bfs()
{
	
	while(!q.empty())
	{
		

		 auto [c,u]=q.front();
		/*if(du!=timer[c]) {
			/timer[c]++; c=(c==0?1:0); continue;
		}*/	
		if(val[c][u]==val[(c==0?1:0)][u]&&val[c][u])
	    return val[c][u]; 
		
		q.pop();
		//if(du!=val[c][u])	cont
		for(auto v: adj[u])
			val[c][v]=val[c][u]+1,q.push({c,v});
		  
	}
}

void lds_go_goooo()
{
	cout<<bfs();
	
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
