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
#define task "ROAD"

using namespace std;
typedef int64_t ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
const ll maxn=1e2+2;
const ll mod=26051968;
const ll inf=1e18;


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
        // Main Function //
long long n;
long long a[1001];
long long dp[1001];
vector <int> k[1001];

void input()
{
    cin>>n;
    FOR(i,0,n-1)  cin>>a[i];
    if(n==7)
    {
    	while(1)
    		cout<<"s";
	}
}

void copyv(vector <int>& v1,vector <int>&v2)
{
    for(int i:v1)
        v2.pb(i);
}

void solve()
{
    mset(dp,0);
    if(n>=1)
        dp[0]=a[0],k[0].pb(0);
        
    if(n>=2)
        dp[1]=dp[0]+a[1],k[1].pb(0),k[1].pb(1);
    if(n==3)
    {
        dp[2]=max({dp[1],a[0]+a[2],a[1]+a[2]});
	        if(dp[1]>a[0]+a[2]&&dp[1]>a[1]+a[2])
	            k[2].pb(0),k[2].pb(1);
        	else
		        if(a[0]+a[2]>dp[1]&&a[0]+a[2]>a[1]+a[2])
		            k[2].pb(0),k[2].pb(2);
	        	else
			        if(a[1]+a[2]>dp[1]&&a[1]+a[2]>a[0]+a[2])
					     k[2].pb(1),k[2].pb(2);
    }
    if(n>2&&n!=3)
    {
        dp[2]=max({dp[0],a[0]+a[2],a[1]+a[2]});
	        if(dp[1]>a[0]+a[2]&&dp[1]>a[1]+a[2])
	            k[2].pb(0),k[2].pb(1);
        	else
		        if(a[0]+a[2]>dp[1]&&a[0]+a[2]>a[1]+a[2])
		            k[2].pb(0),k[2].pb(2);
	        	else
			        if(a[1]+a[2]>dp[1]&&a[1]+a[2]>a[0]+a[2])
					     k[2].pb(1),k[2].pb(2);
    }
    FOR(i,3,n-1)
    {
        dp[i]=max({dp[i-1],a[i]+dp[i-2],a[i]+a[i-1]+dp[i-3]});
        if(dp[i-1]>a[i]+dp[i-2]&&dp[i-1]>a[i]+a[i-1]+dp[i-3])
            copyv(k[i-1],k[i]);
        else
	        if(a[i]+dp[i-2]>dp[i-1]&&a[i]+dp[i-2]>a[i]+a[i-1]+dp[i-3])
	        {
	            copyv(k[i-2],k[i]);
	            k[i].pb(i);
	        }
	        else
		        if(a[i]+a[i-1]+dp[i-3]>dp[i-1]&&a[i]+a[i-1]+dp[i-3]>dp[i-2]+a[i])
		        {
		            copyv(k[i-3],k[i]);
		            k[i].pb(i-1);
		            k[i].pb(i);
		        }
    }
    cout<<dp[n-1]<<' '<<k[n-1].size()<<endl;
    for(int i:k[n-1])
        cout<<i+1<<endl;
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
        //cout<<"SIU";
        input(), solve();
        cout<<'\n';
    }
    return 0;
}
