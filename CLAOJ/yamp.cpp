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
#define int ll
const int SQRT=sqrt(200001)+1;
ll n,k;
ll dp[21][200001];
ll a[200001];
ll cnt[200001];
int curl=1,curr=0;
int ans=0;

void add(int i)
{
	ans+=cnt[i]++;
}

void sub(int i)
{
	ans-=--cnt[i];
}

ll calc(int l,int r)
{
	while(curl<l)	sub(a[curl++]);
	while(curl>l)	add(a[--curl]);
	while(curr>r)	sub(a[curr--]);
	while(curr<r)	add(a[++curr]);
	return ans;
}
void input()
{
	cin>>n>>k;
	FOR(i,1,n)
	{
		cin>>a[i];
	}
}

void comp(int i,int l, int r,int optl, int optr)
{
	if(r<l)	return;
	int mid=(l+r)/2;
	ii best ={inf,-1};
    FOR(j,optl,min(optr,mid))
		if(minimize(best.fi,calc(j,mid)+	dp[i-1][j-1]))
			best.se=j;
	
	ll opt=best.se;
		dp[i][mid]=best.first;
	comp(i,l,mid-1,optl,opt);
	comp(i,mid+1,r,opt,optr);	

}

void lds_go_goooo()
{
	mset(dp,0x3f);
	dp[0][0]=0;
//	FOR(i,0,n)	dp[1][i]=calc(1,i);
//	dp[1][0]=inf;
	//cout<<calc(4,7)<<endl;
	FOR(i,1,k)
		comp(i,1,n,1,n);
	cout<<dp[k][n];
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
