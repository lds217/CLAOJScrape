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
const ll LOG = log2(2e5+1)+2;

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

int n,m,h[200005],LCA[200005][LOG+2];
vector <int> k[200005],day[200005];


void input()
{
	cin>>n>>m;
	FOR(i,1,n)
	{
		int x,y;
		cin>>x>>y;
		if(y)
		{
			k[i].pb(y);
			k[y].pb(i);
		}
		day[x].pb(i);
	}

}




void dfs(int u, int lvl, int par)
{
	h[u]=lvl;
	LCA[u][0]=par;
	for(int v: k[u])
		if(v!=par)
			dfs(v,lvl+1,u);
}

void init()
{

	dfs(1,1,-1);
	for(int i=1;i<=LOG;i++)
		for(int j=1;j<=n;j++)
			if(LCA[j][i-1]!=-1)
			{
				int par= LCA[j][i-1];
				LCA[j][i]=LCA[par][i-1];
			}
			
}

int getLCA(int a, int b)
{
	if(h[b]<h[a])
		swap(a,b);
	int d=h[b]-h[a];

	while(d>0)
	{
		int i= log2(d);
		b=LCA[b][i];
		d-=(1<<i);
	}
	if(a==b)return a;
	FORD(i,LOG,0)
		if(LCA[a][i]!= -1 && LCA[a][i]!= LCA[b][i])
			a=LCA[a][i],b=LCA[b][i];
	
	return LCA[a][0];
}



void lds_go_goooo()
{
//	bfs(1);
	mset(LCA,-1);
	init();
	FOR(i,1,m)
	{
		int deepest=day[i][0];
		for(int &j:day[i])	
			if(h[j]>h[deepest])
				deepest=j;
	
		int ans=0;
		for(int &j:day[i])	
		{
			int p=getLCA(deepest,j);
			ans=max(ans,h[j]+h[deepest]-2*h[p]);
		}
		cout<<ans<<endl;
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
    	//sub1
        input(), lds_go_goooo();
        cout<<'\n';
    }
    return 0;
}
