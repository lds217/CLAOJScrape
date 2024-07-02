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

#define int long long

void input()
{
	
}
void lds_go_goooo()
{
	int n,num=0;
	cin>>n;
	ll a[1025];
	mset(a,0);
	ll dig[10]={0};
	while(n--)
	{
		int tmp;
		cin>>tmp;
		while(tmp)
		{
			num=num | (1<<tmp%10);
			tmp/=10;
		}
		a[num]++;
//		cout<<num<<' ';
		num=0;
	}
	int ans=0;
	FOR(i,1,1023)
		FOR(j,1,1023)
			if(i!=j && (i&j))
				ans+=(a[i]*a[j]);
	FOR(i,1,1023)
		ans+=(a[i]*(a[i]-1));
		cout<<ans/2;	
}

signed main()
{
 	ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout<<(1<<2)<<endl;
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
