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
const ll maxn=3*1e7+10;
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
#define int ll
//main

/*
3 2
1 2
-3 1
2 1


2
*/

int n,d;
ii a[maxn];
ll dp[maxn];
vector <ii> b;
void input()
{
	
}



void lds_go_goooo()
{
	cin>>n>>d;
	FOR(i,1,n)
	{
		cin>>a[i].fi>>a[i].se;
		a[i].fi+=2e6+1;
		ll t=d*d-a[i].se*a[i].se;
		if(t<0||a[i].se>d)
		{
			cout<<-1;
			return;
		}
		double tmp=sqrt(d*d-a[i].se*a[i].se);
	//	dp[a[i].fi-tmp]++;
	//	dp[a[i].fi+tmp+1]--;
		b.pb({a[i].fi-tmp,a[i].fi+tmp});
		
	}
	ll res=0;
	double left=0;
	sort(ALL(b));
	for(auto [u,v]: b)
	{
//		cout<<u<<' '<<v<<endl;
		if(left<u)	left=v,res++;
		else
			if(left>v)
				left=v;
	}
	cout<<res;
	
	
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
