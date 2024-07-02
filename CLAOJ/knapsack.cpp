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
#define task "KNAPSACK"

using namespace std;
typedef int64_t ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
const ll maxn=2*1e4+2;
const ll mod=26051968;
const ll inf=1e18;
#define int long long
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

struct lp{
	long long w,val;
} a[41];
long long n,M;
void input()
{
	cin>>n>>M;
	mset(a,0);
	FOR(i,1,n)	cin>>a[i-1].w;
	FOR(i,1,n)	cin>>a[i-1].val;
}

long long Try(int i, long long w , long long val)
{
    if(w > M)
        return 0;
    if(i == n)
    {
        if(w <= M)
        return val;
        else return 0;
    }
    int l = Try(i + 1 ,w + a[i].w, val + a[i].val);
    int r = Try(i + 1, w , val);
    return max(l ,r);
}
void lds_go_goooo()
{
	//sort(a,a+n,[](lp l,lp p)
	//{
	//	return ( long double)l.val/l.w> (long double)p.val/p.w;
	//});
	cout<<Try(0,0,0);
}

signed main()
{
 	ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen(task".INP", "r", stdin);
    freopen(task".OUT", "w", stdout);
    ll test_case=1; cin>>test_case;
    while(test_case--)
    {
        input(), lds_go_goooo();
        cout<<'\n';
    }
    return 0;
}
