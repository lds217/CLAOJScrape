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
#define task "LAWRENCE"

using namespace std;
typedef int64_t ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
const ll maxn=2e3+10;
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

ll n,m,a[501],dp[501][501],cost[501][501];
void input()
{
	cin>>n>>m;
	FOR(i,1,n)	cin>>a[i];
}

void lds_go_goooo()
{
	FORD(i,n,1)
	{
		ll sum=a[i];
		FORD(j,i-1,1)
		{
			cost[j][i]=cost[j+1][i]+a[j]*sum;
			sum+=a[j];
		}
	}
	if(m==0)
	{
	    cout<<cost[1][n];
	    return;
	}
	mset(dp,0x3f);
	dp[0][0]=0;
//	cout<<cost[2][4]<<endl;
	FOR(z,1,m)
		FOR(i,1,n)
			FOR(j,1,i)
				minimize(dp[z][i],dp[z-1][j-1]+cost[j][i]);
/*				
	FOR(i,1,m)
	{
		FOR(j,1,n)
			cout<<dp[i][j]<<' ';
		cout<<endl;
	}*/
	ll res=1e9;
	FOR(i,1,n)
		res=min(dp[m][i]+cost[i+1][n],res);
	cout<<res;

}

signed main()
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
