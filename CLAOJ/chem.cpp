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
struct bot{
	ll first,second,id;
}a[maxn];
ll n,sum=0;
void input()
{
	cin>>n;
	FOR(i,1,n)
	{
		ll x,y;
		cin>>x>>y;
		a[i]={x,y,i};
		sum+=x;
	}
}
ll ans[maxn],cnt=0;
void lds_go_goooo()
{
	sort(a+1,a+n+1,[](bot a,bot b)
	{
		return a.se>b.se;
	});
	
	FOR(i,1,n)
		if(sum>=a[i].se)
		{
			sum-=a[i].se;
			ans[a[i].id]=a[i].second;
		}
		else
		{
			ans[a[i].id]=sum;
			cnt=n-i;
			break;
		}
		cout<<cnt<<endl;
	FOR(i,1,n)
		cout<<ans[i]<<' ';
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
