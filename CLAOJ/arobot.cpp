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

const int moveX[]={-1, +0, +1, +0};
const int moveY[]={+0, -1, +0, +1};

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
#define int ll
//main

int n,h,w;
char a[501][501];
int dp[10][10][501][501];
ii precal[501][501][5];
ii pos[10];
int cnt=0;
void input()
{
	cin>>n>>w>>h;
	FOR(i,1,h)
		FOR(j,1,w)
		{
			cin>>a[i][j];
			if(a[i][j]>='1'&&a[i][j]<='9')
				pos[a[i][j]-'0']={i,j};
			else
				if(a[i][j]=='A'||a[i][j]=='C')
					cnt++;
		}
}
// clockwise 4 anti 3

// heading go to next


int check(int u, int v) {
    return (1 <= u && u <= h) && (1 <= v && v <= w) && a[u][v] != 'x';
}

ii move(int u, int v, int w) {
    auto &res = precal[u][v][w];
    if (res.first != 0) return precal[u][v][w];
	
    
    if(a[u][v]=='A')
    	w =(w+1)%4;
    if (a[u][v]=='C')
     	w=(w+3)%4;
    if (check(u+moveX[w],v+moveY[w]))
        res = move(u+moveX[w],v+moveY[w],w);
    else    
        res = make_pair(u, v);
    return res;
}
//0 1 5 0 3 0 4 0 0 1
//5 0 0 0 2 0 0 0 0 0
//4 0 0 0 6 0 0 0 0 0
//0 0 0 0 0 0 0 0 0 0
//4 3 4 0 3 0 3 0 0 2
void bfs(int l,int u,int v)
{
	dp[l][l][u][v]=0;
	queue<ii> q;
	q.push({u,v});
	while(!q.empty())
	{
		auto [x,y] = q.front();
		q.pop();
		FOR(dir,0,3)
		{
			ii o = move(x,y,dir);
			auto [nx,ny] = o;
			if(minimize(dp[l][l][nx][ny],dp[l][l][x][y]+1))	
				q.push({nx,ny});
		}
	}
}

void dijkstra(int l,int r)
{
	priority_queue<pair<int,ii>> pq;
	FOR(i,1,h)
		FOR(j,1,w) 
			if(dp[l][r][i][j]!=inf)
				pq.push({-dp[l][r][i][j],{i,j}});
	
	while(!pq.empty())
	{
		auto [v,p]= pq.top();
		pq.pop();
		auto [x,y]=p;
		FOR(w,0,3)
		{
			auto [nx,ny]= move(x,y,w);
			if (minimize(dp[l][r][nx][ny], dp[l][r][x][y] + 1))
                pq.push({-dp[l][r][nx][ny], {nx, ny}});
		}
	}
}

// 0 1 2 3
int ko[15][15];
void go(int i,int j,int dir)
{
	if(i+moveX[dir]>0&&j+moveY[dir]>0&&j+moveY[dir]<=w&&i+moveX[dir]<=h)
		go(i+moveX[dir],j+moveY[dir],dir);
}

void merge(int l1, int r1, int l2, int r2) {
    FOR(i, 1, h) FOR(j, 1, w)
        minimize(dp[l1][r2][i][j], dp[l1][r1][i][j] + dp[l2][r2][i][j]);
}

void lds_go_goooo()
{
//	if(n==2&&cnt<0)
//	{
//		mset(ko,0x3f);
//		ll ans=inf;
//		int i=pos[1].fi;
//		int j = pos [1].se;
//		
//		FOR(w,0,3)
//			go(i,j,w);
//		 i=pos[2].fi;
//		 j = pos [2].se;
//		FOR(w,0,3)
//			go(i,j,w);
//		return;
//	}
	FOR(l, 1, n) FOR(r, l, n)
        FOR(i, 1, h) FOR(j, 1, w) {
            dp[l][r][i][j] = inf;
    }
	
	FOR(i,1,h)
		FOR(j,1,w)
			if(a[i][j]>='1'&&a[i][j]<='9')
				bfs(a[i][j]-'0',i,j);
	
//	FOR(i,1,h){
//		FOR(j,1,w)
//		{
//			if(dp[2][2][i][j]==inf)
//				cout<<0;
//			else
//				cout<<dp[2][2][i][j];
//			cout<<' ';
//		}
//		cout<<endl;
//	}
	 FOR(len,2,n) {
        FOR(l,1,n-len+1) {
            int r=l +len-1;
            FOR(k,l,r-1)
                FOR(i,1,h)
                	FOR(j,1,w)
                		minimize(dp[l][r][i][j],dp[l][k][i][j]+dp[k+1][r][i][j]);
            dijkstra(l, r);
        }
    }
//		FOR(i,1,h){
//		FOR(j,1,w)
//		{
//			if(dp[1][n][i][j]==inf)
//				cout<<' ';
//			else
//				cout<<dp[1][n][i][j];
//			cout<<' ';
//		}
//		cout<<endl;
//	}
	ll ans=inf;
	FOR(i,1,h)
		FOR(j,1,w)
			minimize(ans,dp[1][n][i][j]);
	if(ans==inf)
		cout<<-1;
	else
		cout<<ans;		
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
