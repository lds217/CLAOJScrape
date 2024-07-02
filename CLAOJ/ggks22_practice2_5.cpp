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
const ll maxn=255;
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

ll n,m,maxx=0;
char a[maxn][maxn];
ll val[maxn][maxn];
bool vis[maxn][maxn];
queue <ii> q;

void clear( queue<ii> &q )
{
   queue<ii> empty;
   swap( q, empty );
}

void reset()
{
	mset(a,0);
	mset(val,0);
	mset(vis,0);
	clear(q);
}

void input()
{
	reset();
	cin>>n>>m;
	FOR(i,1,n)
		FOR(j,1,m)
		{
			cin>>a[i][j];
			if(a[i][j]=='1')
				q.push({i,j}),val[i][j]=0,vis[i][j]=1;
		}
}


void prepare()
{
	maxx=0;
	while(!q.empty())
	{
		int x=q.front().fi;
		int y=q.front().se;
		q.pop();
		FOR(i,0,3)
		{
			int nx=x+moveX[i];
			int ny=y+moveY[i];
			if(nx<1||ny<1||nx>n||ny>m)	continue;
			if(vis[nx][ny]==0)
			{
				val[nx][ny]=val[x][y]+1;
				maxx=max(maxx,val[nx][ny]);
				vis[nx][ny]=1;
				q.push({nx,ny});
			}
		}
	}
}

bool ck(ll mid)
{
	ll max_sum=LLONG_MIN,max_sub=LLONG_MIN;
	ll min_sum=LLONG_MAX,min_sub=LLONG_MAX;
	bool co=0;
	FOR(i,1,n)
		FOR(j,1,m)	
			if(val[i][j]>mid)
			{
				maximize(max_sum,i+j);
				maximize(max_sub,i-j);
				minimize(min_sum,i+j);
				minimize(min_sub,i-j);
				co=1;
			}
	if(!co)
		return 0;
	
	FOR(i,1,n)
		FOR(j,1,m)
		{
			ll greatest=0;
			greatest=max({abs(min_sum-(i+j)),abs(max_sum-(i+j)),abs(max_sub-(i-j)),abs(min_sub-(i-j))});
			if(greatest<=mid)
				return 1;
		}
	return 0;
			
}

void lds_go_goooo()
{
	prepare();
	/*FOR(i,1,n)
	{
		FOR(j,1,m)
			cout<<val[i][j]<<' ';
		cout<<endl;
	}*/
	ll l= 0,r = maxx,ans=maxx;
	while(r>=l)
	{
		ll mid = (l+r)/2;
		if(ck(mid))r=mid-1,ans=mid;
		else	l=mid+1;
	}
	cout<<ans;
}

int main()
{
 	ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen(task".INP", "r", stdin);
    //freopen(task".OUT", "w", stdout);
     ll test_case=1; cin>>test_case;
    FOR(i,1,test_case)
    {
         input();cout<<"Case #"<<i<<": " ;lds_go_goooo();
        cout<<'\n';
    }
    return 0;
}
