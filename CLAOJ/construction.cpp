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

long long n;
long long a[maxn],b[maxn];

void input()
{
	mset(a,0);
	mset(b,0);
	cin>>n;
	FOR(i,1,n)	cin>>a[i];
	FOR(i,1,n)	cin>>b[i];
}

long long cal(int x)
{
	long long ans=0;
	FOR(i,1,n)
		ans+=abs(a[i]-x)*b[i];
	return ans;
}

void lds_go_goooo()
{
	int l=1,r=1e4;
	while(r-l>4)
	{
		int m1=(l+r)/2;
		int m2=m1+1;
		if(cal(m1)>cal(m2)) l=m1;
		else	r=m1;
	}
	long long ans=1e12;
	FOR(i,l,r)
		ans=min(ans,cal(i));
	cout<<ans;
}

int main()
{
 	ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen(task".INP", "r", stdin);
    //freopen(task".OUT", "w", stdout);
    ll test_case=1; cin>>test_case;
    while(test_case--)
    {
        input(), lds_go_goooo();
        cout<<'\n';
    }
    return 0;
}
