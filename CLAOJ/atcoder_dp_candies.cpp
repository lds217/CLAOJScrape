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
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
const ll maxn=2*1e5+2;
const ll mod=1e9+7;
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

long long n,k;
long long dp[maxn];
void input()
{
	
}

long long submod(ll a,ll b)
{
	ll tmp=0;
	tmp=a-b;
	if(tmp<0)
		return tmp+mod;
	return tmp;
}

void lds_go_goooo()
{
	cin>>n>>k;
	dp[0]=1;
	FOR(i,0,n-1)
	{
		long long u;
		cin>>u;
		ll presum[maxn];
		mset(presum,0);
		FORD(used,k,0)
		{
			int l=used+1;
			int r=used+min(u,k-used);
			if(l<=r)
			{
				presum[l]=(presum[l]+dp[used])%mod;
				if(r<=k-1)
					presum[r+1]=submod(presum[r+1],dp[used]);	
			}
		}
		ll sum=0;
		FOR(i,1,k)
		{
			sum=(sum+presum[i])%mod;
			dp[i]=(dp[i]+sum)%mod;
		}
	}
	cout<<dp[k]%mod;
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
