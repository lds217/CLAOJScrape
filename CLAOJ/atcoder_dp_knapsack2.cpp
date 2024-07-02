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

long long n,W,dp[106][100005],w[105],v[105];

void input()
{
	cin>>n>>W;
	
	for(int i=0;i<n;i++)
		cin>>w[i]>>v[i];
		

}
void lds_go_goo_goooo()
{
    	for(int i=0;i<100;i++)
		for(int j=0;j<=100000;j++)
			dp[i][j]=inf;
	
	dp[0][0]=0;
	dp[0][v[0]]=w[0];
	
	for(int i=1;i<n;i++)
	{
		dp[i][0]=0;
		for(int j=1;j<=100000;j++)
		{
			dp[i][j]=dp[i-1][j];
			if(j>=v[i])
				dp[i][j]=min(dp[i][j],  w[i]+dp[i-1][j-v[i]]);
		}
	}
	for(int j=100000;j>=0;j--)
		if(dp[n-1][j] <= W)
		{
			cout<<j;
			return ;
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
        input(), lds_go_goo_goooo();
        cout<<'\n';
    }
    return 0;
}
