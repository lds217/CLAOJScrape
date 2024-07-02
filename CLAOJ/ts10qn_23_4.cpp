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
#define task "pass"

using namespace std;
typedef int64_t ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
const ll maxn=2*1e6+2;
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

ll a[maxn];
string s;
void input()
{
	mset(a,0);

	cin>>s;
	FOR(i,0,s.size()-1)
		a[i+1]=a[i]+s[i]-'0';
	
}
ii dupp[maxn];
ll l1,l2,r1,r2;
bool check(int mid)
{
	mset(dupp,0);	
	FOR(i,mid,s.size())
		if(dupp[a[i]-a[i-mid]].fi)
		{
			r1=dupp[a[i]-a[i-mid]].se,r2=i;
			return 1;
		}
		else
			dupp[a[i]-a[i-mid]].fi=1,dupp[a[i]-a[i-mid]].se=i;
	return 0;
		
}

void lds_go_goooo()
{
	ll l=1,r=s.size(),ans=-1;
	while(r>=l)
	{
		ll mid=(r+l)/2;
		if(check(mid))	l=mid+1,ans=mid;
		else	r=mid-1;
	}
	swap(r1,r2);
	if(ans!=-1)
	cout<<r1-ans+1<<' '<<r1<<' '<<r2-ans+1<<' '<<r2;
	else
		cout<<ans;
}

int main()
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
