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
#define task "DAOVANG"

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

ll n,k;
ll a[maxn];

void input()
{
	cin>>n>>k;
	FOR(i,1,n)
		cin>>a[i];
	sort(a+1,a+n+1);
}

bool check(ll r)
{
	ll cnt=0;
	FOR(i,1,n)
	{
		int j=i+1;
		while(a[j]<=a[i]+r*2+1&&j<=n)
			j++;
		cnt++;
		i=j-1;
			if(cnt>k)
				return 0;
	}

	return 1;
}

void lds_go_goooo()
{
	ll ans=0;
	ll l=0,r=1e9;
	while(r>=l)
	{
		
		ll mid=(l+r)/2;
		//cout<<l<<' '<<r<<' '<<mid<<' '<<endl;
		if(check(mid))
			r=mid-1,ans=mid;
		else
			l=mid+1;
	}
	cout<<ans;
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
