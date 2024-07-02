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

int POW(ll a, ll b)
{
    if (b==0) return 1;
    ll tmp=POW(a, b/2);
    return b%2==0 ? (tmp*tmp)%mod : ((tmp*tmp) % mod*a) % mod;
}

//main

struct point{
	int 	x,y;
}p[maxn];

int H,W,N;

long long gt[2000005],igt[2000005],dp[2000005];

void input()
{
	cin>>H>>W>>N;
	FOR(i,1,N)
		cin>>p[i].x>>p[i].y;
	p[N+1].x=H,p[N+1].y=W;
}

void prepare(int lim)
{
	gt[0]=1;
	FOR(i,1,lim)
		gt[i]=(gt[i-1]*i)%mod;
	igt[lim]=POW(gt[lim],mod-2);
	FORD(i,lim,1)
		igt[i-1]=(igt[i]*i)%mod;
}

long long prob(int x,int y, int i, int j)//x y is fixed
{
	long long n=x-i+y-j;
	long long k=x-i;
	return (gt[n]*igt[k])%mod* igt[n-k]%mod;
}

void solve()
{
	sort(p+1,p+N+2,[](point a, point b){
		if(a.x==b.x)
			return a.y<b.y;
		return a.x<b.x;
	});
//	FOR(i,1,N+1)
//		cout<<p[i].x<<" "<<p[i].y<<endl;
//	cout<<endl;
	prepare(H+W);
	N++;
	FOR(i,1,N)
	{
		long long curr=prob(p[i].x,p[i].y,1,1)%mod;
		FOR(j,1,i-1)
			if(p[i].y>=p[j].y)
				curr=(curr-dp[j]*prob(p[i].x,p[i].y,p[j].x,p[j].y))%mod;
		if(curr<0)
			curr=(curr+mod)%mod;
		dp[i]=curr;
	}
	cout<<dp[N];
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
