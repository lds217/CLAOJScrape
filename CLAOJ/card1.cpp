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

ll n,a[maxn],dp[maxn][maxn],opt[maxn][maxn];

void input()
{
	cin>>n;
	FOR(i,1,n)
		cin>>a[i],a[i]+=a[i-1];
}
void lds_go_goooo()
{
	//FOR(i,1,n)	cout<<a[i]<<' ';
	mset(dp,0);
	FOR(i,1,n)		opt[i][i]=i;
	FOR(i,1,n)
	{
		
		FORD(j,i,1)
		{
			ll curr=INT_MAX;
			FOR(k,max(j,opt[j][i-1]),min(opt[j+1][i],i-1))
				if(maximize(dp[j][i],min(dp[j][k]+a[k]-a[j-1],dp[k+1][i]+a[i]-a[k])))
					opt[j][i]=k;
		}
	}
	cout<<dp[1][n];
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
