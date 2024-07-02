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
#define task "LINE"

using namespace std;
typedef int64_t ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
const ll maxn=2*1e4+2;
const ll mod=26051968;
const ll inf=1e18;

int moveX[] = {-1,-2,-2,-1,1,2,2,1};
int moveY[] = {-2,-1,1,2,2,1,-1,-2};

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
ll n,m,k=1;
ll dp[101][101][201];
char a[1000][1000];
struct lds {
	int x,y,z;
};
vector<lds> pos_of_k;

void input()
{
	mset(dp,0x3f);
	cin>>n>>m;
	FOR(i,1,n)
		FOR(j,1,m)
		{
			cin>>a[i][j];
			if(a[i][j]=='M')
				pos_of_k.pb({i,j,k}),k++;
		}
}

void bfs(int sx,int sy,int id)
{
	queue <ii> q;
	q.push({sx,sy});
	dp[sx][sy][id]=0;
	while(!q.empty())
	{
		auto [x,y]=q.front();
		q.pop();
		FOR(i,0,7)
		{
			int nx=x+moveX[i];
			int ny=y+moveY[i];
			if(nx>n||ny>m||nx<1||ny<1)	continue;
			if(a[nx][ny]!='#'&&minimize(dp[nx][ny][id],dp[x][y][id]+1))
				q.push({nx,ny});
		}
	}
}

int matchX[2501],used[2501];
int cur=0;
vector <int> adj[10000];
bool DFS(int u)
{
	if(used[u]==cur)	return 0;
	used[u]=cur;
	for(int v:adj[u])
		if(matchX[v]==0||DFS(matchX[v]))
		{
			matchX[v]=u;
			return 1;
		}
	return 0;
}


bool check(int mid)
{
	
	FOR(i,1,n)
		FOR(j,1,m)
		{
			ii pos[51];
			bool ok=1;
			FOR(z,1,k)
				if(j+z-1>m||a[i][j+z-1]=='#')
				{
					ok=0;
					break;
				}
				else
					pos[z]={i,j+z-1};
		//	cout<<"position"<<endl;
		//	FOR(i,1,k)
		//		cout<<pos[i].fi<<' '<<pos[i].se<<endl;
		//	cout<<"ok:"<<ok<<endl;
			if(ok==0)
				continue;
			mset(matchX,0);
			mset(used,0);
			FOR(l,0,k+1)
				adj[l].clear();
			int d=0;
			FOR(x,1,k)
				FOR(y,1,k)
					if(dp[pos[y].fi][pos[y].se][x]<=mid)	{
				//	cout<<x<<" "<<y<<endl;
					adj[x].pb(y),d++;}
			//cout<<endl;
			int res=0;
			for(cur=1;cur<=d;cur++)
				res+=DFS(cur);
		//	cout<<res<<endl;
		//	FOR(x,1,k)
		//		if(matchX[x])	cout<<x<<' '<<matchX[x]<<endl;
		//	cout<<endl;
			if(res!=k)
				continue;
			
			return 1;
		}
	return 0;
}

void lds_go_goooo()
{
	k--;
	
	//cout<<k;
	for(auto [sx,sy,id] : pos_of_k)
		bfs(sx,sy,id);
	//cout<<check(2)<<endl;
/*	FOR(z,1,k)
	{
		FOR(i,1,n)
		{
			FOR(j,1,m)	cout<<dp[i][j][z]<<' ';
			cout<<endl;
		}
		cout<<endl;
	}*/
	ll l=0,r=m*n,ans=1e9;
	while(r>=l)
	{
		
		int mid=(l+r)/2;
		//cout<<l<<' '<<mid<<' '<<r<<endl;
		if(check(mid))
			r=mid-1,ans=mid;
		else
			l=mid+1;
	}
	cout<<ans;
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
