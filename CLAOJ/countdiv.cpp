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
#define int long long
using namespace std;
typedef __int128_t ll;
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

long long n,l,r,a[30];
vector<ii> ans;
void input()
{
	
}

ll get(ll a,ll b)
{
	return (a*b)/__gcd(a,b);
}


void backtrack(ll pos,ll sum,ll cnt)
{
	if(pos>n)
	{
		if(cnt)	ans.pb({sum,cnt});
		return;
	}
	backtrack(pos+1,sum,cnt);
	if(get(a[pos],sum)<r)
	backtrack(pos+1,get(a[pos],sum),cnt+1);
}

void lds_go_goooo()
{
	while(cin>>n)
	{
	    cin>>l>>r;
		mset(a,0);
		ans.clear();
		FOR(i,1,n)
			cin>>a[i];
		backtrack(1,1,0);
		long long res=0;
		for(ii x:ans)
		{
			ll tmp=r/x.fi-(l-1)/x.fi;
			if(x.se%2)	res+=tmp;
			else	res-=tmp;
		}
		cout<<res<<"\n";
	}
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
