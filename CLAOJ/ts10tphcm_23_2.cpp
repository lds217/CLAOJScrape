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
#define task "GIAOHANG"

using namespace std;
typedef int64_t ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
const ll maxn=3*1e5+2;
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

ll n,m;
ii a[maxn];
	int ind=1;
void input()
{
	cin>>n>>m;

	FOR(i,1,n)	
	{
		int x,y;
		cin>>x>>y;
		if(x>y)
			a[ind++]={x,y};
	}
}
void lds_go_goooo()
{
	n=ind-1;
	sort(a+1,a+n+1,[](ii a, ii b)
	{
		if(a.se==b.se)
			return	a.fi>b.fi;
		return a.se<b.se;
	});
	//FOR(i,1,n)
	//	cout<<a[i].fi<<' '<<a[i].se<<endl;
	ll res=0;
	ll left=a[1].se;
	ll right=a[1].fi;
	FOR(i,1,n)
	{
		left=min(left,a[i].se);
		right=max(right,a[i].fi);
		if((i==n)||(left>a[i+1].fi)||(right<a[i+1].se))
		{
			res+=(right-left)*2;
			if(i==n)	break;
			left=a[i+1].se;
			right=a[i+1].fi;
		}
	}
	cout<<(res+m);
}

int main()
{
 	ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen(task".INP", "r", stdin);
    freopen(task".OUT", "w", stdout);
    ll test_case=1; //cin>>test_case;
    while(test_case--)
    {
        input(), lds_go_goooo();
        cout<<'\n';
    }
    return 0;
}
