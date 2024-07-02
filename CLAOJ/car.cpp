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
const ll maxn=3*1e4+2;
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

int a,b,c,n,k;
ll dp[maxn][1000];
long long Height[maxn];
long long prepos[1000000];

void input()
{
	cin>>a>>b>>c>>n>>k;
    string str;
    cin>>str;
    long long minn=1e9;
    mset(dp,0);
    mset(Height,0);
    FOR(i,0,n-1)
    {
        if(str[i]!='R')
            Height[i+1]=Height[i]+(str[i]=='G'?1:-1);
        else
            Height[i+1]=Height[i];
        minn=min(minn,Height[i+1]);
    }
    FOR(i,0,n)    Height[i]-=minn;// cout<<Height[i]<<' ';
    mset(prepos,-1);
    
    //cout<<endl;
}
int pos[maxn];
void prepare()
{
    
    FOR(i,0,n)
    {
        pos[i]=prepos[Height[i]];
        prepos[Height[i]]=i;
    }
}

void solve()
{
    prepare();
	int bridge=0;
	mset(dp, 0x3f);
    dp[0][0]=0;
	FOR(i,1,n)
	{
	    if(Height[i]==Height[i-1])
	        FOR(j,0,min(bridge,k))
	            dp[i][j]=dp[i-1][j]+a;
	    else
	        if(pos[i]==-1)
	            FOR(j,0,min(bridge,k))
	                dp[i][j]=dp[i-1][j]+b;
	        else
	        {
	            bridge++;
	            dp[i][0]=dp[i-1][0]+b;
	            FOR(j,1,min(bridge,k))
	                dp[i][j]=min(dp[i-1][j]+b,dp[pos[i]][j-1]+(i-pos[i])*c);
	        }
	}
	ll final=1e9;
    FOR(i,0,k)
	    final=min(final,dp[n][i]);
	cout<<final;
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
        input(), solve();
        cout<<'\n';
    }
    return 0;
}
