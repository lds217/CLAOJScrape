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

int n,q;
bool vs[503][503];
ll dp1[503][503],dp2[503][503];
void input()
{
	mset(dp1,0x3f);
	mset(dp2,0x3f);
	cin>>n>>q;	
	while(q--)
	{
		int u,v;
		cin>>u>>v;
		vs[u][v]=1;
	}
}
void lds_go_goooo()
{
	dp1[1][1]=0;
	dp2[1][n]=0;
	FOR(i,1,n)
		FOR(j,1,n)
			if(!vs[i][j])
			{	
				if(!vs[i-1][j-1])	minimize(dp1[i][j],dp1[i-1][j-1]+1);	
				if(!vs[i-1][j])	minimize(dp1[i][j],dp1[i-1][j]+1);
				if(!vs[i][j-1])	minimize(dp1[i][j],dp1[i][j-1]+1);
			}
	
	FOR(i,1,n)
		FORD(j,n,1)
			if(!vs[i][j])
			{	
				if(!vs[i-1][j+1])	minimize(dp2[i][j],dp2[i-1][j+1]+1);	
				if(!vs[i-1][j])	minimize(dp2[i][j],dp2[i-1][j]+1);
				if(!vs[i][j+1])	minimize(dp2[i][j],dp2[i][j+1]+1);
			}
	ll ans=1e9;	
	FOR(i,1,n)
	{
		FOR(j,1,n)
			if(!vs[i][j])
				if(dp1[i][j]==dp2[i][j])
				minimize(ans,dp1[i][j]);			
	}
		//		
		
	cout<<ans;
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
