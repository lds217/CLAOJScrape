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
#define task ""

using namespace std;
typedef int64_t ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
const ll maxn=1e3+2;
const ll mod=26051968;
const ll inf=1e18;


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
        // Main Function //
ii K[maxn];
vector <ii> ans[maxn];
int n,longest=0,final;

void input()
{
	cin>>n;
	FOR(i,1,n)
		cin>>K[i].fi>>K[i].se;
}

void solve()
{
	
	FOR(i,1,n)
	{
		ans[abs(K[i].fi-K[i].se)].push_back({K[i].fi,K[i].se});
		if(ans[abs(K[i].fi-K[i].se)].size()>longest)
			final=abs(K[i].fi-K[i].se), longest=ans[abs(K[i].fi-K[i].se)].size();
		else
			if(ans[abs(K[i].fi-K[i].se)].size()==longest&&final>abs(K[i].fi-K[i].se))	
				final=abs(K[i].fi-K[i].se), longest=ans[abs(K[i].fi-K[i].se)].size();
	}
	cout<<final<<endl;
	for(ii i: ans[final])
		cout<<i.fi<<' '<<i.se<<endl;
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
        input(), solve();
        cout<<'\n';
    }
    return 0;
}
