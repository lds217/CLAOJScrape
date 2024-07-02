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
const ll maxn=1e5+2;
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
long long int n,a[maxn];

void input()
{
	cin>>n;
	FOR(i,1,n)	cin>>a[i];
}

void solve()
{
	long long int sum1=0,sum2=0,sumpos=0,incase= -1e4-4;
	FOR(i,1,n)
	{
		incase=max(incase,a[i]);
		sumpos+=(a[i]>0) ? a[i] : 0 ;
		sum1+=a[i];
		sum2=max(sum1,sum2);
		sum1=max(sum1,0LL);
	}
	if(sumpos==0&&sum2==0)
		cout<<incase<<' '<<incase<<endl;
	else
		cout<<sumpos<<' '<<sum2<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
   // freopen(task".INP", "r", stdin);
   // freopen(task".OUT", "w", stdout);
    ll test_case=1; cin>>test_case;
    while(test_case--)
    {
        input(), solve();
    }
    return 0;
}
