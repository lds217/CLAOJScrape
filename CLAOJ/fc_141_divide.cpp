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
const ll maxn=2*1e5+2;
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

long long a[maxn],pre[maxn],n,ans=1e15;

void input()
{
	mset(a,0);
	mset(pre,0);
	cin>>n;
	FOR(i,1,n)	cin>>a[i];
	
}

long long get(int l,int r)
{
	return pre[r]-pre[l-1];
}

int lp(int l, int r)
{
	long long tmp=-1;
	long long u=l,v=r;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(abs(get(u,mid)-get(mid+1,v))>=abs(get(u,mid+1)-get(mid+2,v)))
			l=mid+1;
		else
			{
				r=mid-1;
				tmp=mid;
			}
	}
	return tmp;
}

long long getmax(int i,int l, int r)
{
	return max({get(1,l),get(l+1,i),get(i+1,r),get(r+1,n)});
}

long long getmin(int i,int l, int r)
{
	return min({get(1,l),get(l+1,i),get(i+1,r),get(r+1,n)});
}

long long solve(int i)
{
	if(i<=1||i>=n-1) return 1e15;
	int left=lp(1,i);
	int right=lp(i+1,n);
	return getmax(i,left,right)-getmin(i,left,right);
}

void lds_go_goooo()
{
	FOR(i,1,n)	pre[i]=pre[i-1]+a[i];
	FOR(i,1,n)
		ans=min(ans,solve(i));
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
