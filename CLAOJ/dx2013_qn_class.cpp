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
#define task "BTPH"

using namespace std;
typedef int64_t ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
const ll maxn=2*1e4+2;
const ll mod=26051968;
const ll inf=1e9;

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

int a[10001],b[50001];
int dp[3][500001];
long long n,k;

void input()
{
	cin>>n>>k;
	FOR(i,1,n)	cin>>a[i];
	FOR(i,1,k)	cin>>b[i];
}
void lds_go_goooo()
{
	mset(dp,0);
	
	FOR(o,1,k)
	{
		int i=o%2+1;
		dp[i][o-1]=inf;
		if(i==2)
			FOR(j,o,n)
			{
				dp[i][j]=min(dp[i][j-1],dp[i-1][j-1]+abs(a[j]-b[o])),dp[i-2][j]=dp[i][j];
				dp[i-2][o-1]=inf;
			}
		else
			FOR(j,o,n)
				dp[i][j]=min(dp[i][j-1],dp[i-1][j-1]+abs(a[j]-b[o]));
	}
	cout<<dp[k%2==0?1:2][n];
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
