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


int n;
ii a[maxn];

void input()
{
	cin>>n;
	FOR(i,1,n)
		cin>>a[i].fi>>a[i].se;
}

bool check(int x)
{
	ll sum=a[1].se-x;
//	cout<<sum<<endl;
	FOR(i,2,n)
	{
	    if(sum>=0)
		    sum=max(0LL,sum-(a[i].fi-a[i-1].fi)*1LL);
	    else
	        sum-=(a[i].fi-a[i-1].fi);
		sum+=a[i].se-x;
//		cout<<i<<' '<<sum<<endl;
	}
	return sum>=0;
			
}

void lds_go_goooo()
{
	sort(a+1,a+n+1);
 	int l=0,r=1e9,ans=0;
 	
 	while(l<=r)
 	{
 		int mid=(l+r)/2;
 		if(check(mid))
 			l=mid+1,ans=mid;
 		else
 			r=mid-1;
	 }
	cout<<ans;
//	check(6);
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
