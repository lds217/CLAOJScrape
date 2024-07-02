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
const ll maxn=1502;
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

ll n,m,k;
ll a[maxn][maxn];

void input()
{
	cin>>n>>m>>k;
	FOR(i,1,n)
		FOR(j,1,m)
			cin>>a[i][j],a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
}

ll check(int x,int y)
{
	int l=0,r=min(x,y),ans=0;;
	while(r>=l)
	{
		int mid=(l+r)/2;
		if(a[x][y]-a[x-mid][y]-a[x][y-mid]+a[x-mid][y-mid]==k) l=mid+1,ans=mid;
		else
			if(a[x][y]-a[x-mid][y]-a[x][y-mid]+a[x-mid][y-mid]>k)
				r=mid-1;
			else
				l=mid+1;
	}
	return ans*ans;
}


void lds_go_goooo()
{
//	cout<<check(3);
	ll ans=0;
	FOR(i,1,n)
		FOR(j,1,m)
			maximize(ans,check(i,j));
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
