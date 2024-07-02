// Template //
#include <bits/stdc++.h>
#define FOR(i, a, b) for(ll i=a, _b=b; i<=_b; i++)
#define FORD(i, a, b) for(ll i=a, _b=b; i>=_b; i--)
#define pb push_back
#define ALL(a) a.begin(), a.end()

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
const ll maxn=5000005;
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


        // Main Function //

//main


long long logab(long long a, long long b)
{
    long long ans = 0;
    while (a > 1) {
        a /= b;
        ans++;
    }
    return ans;
}

long long n,k;

void input()
{
	cin>>n>>k;
}

void lds_go_goooo()
{
    if (k==1)
{
	cout<<n-1<<' '<<n;
	return;
	}
 long long ans=logab(n*(k-1)+1-k,k);
 	if((long long)((pow(k,ans)-1)/(k-1))>=n)
 		ans--;
 	cout<<ans<<' '<<(long long)((pow(k,ans+1)-1)/(k-1));
}


int main()
{
 	ios_base::sync_with_stdio(false);
 	cin.tie(0);
 	cout.tie(0);
    //freopen(task".INP", "r", stdin);
    //freopen(task".OUT", "w", stdout);
    ll test_case=1; cin>>test_case;
    while(test_case--)
    {
        input(); lds_go_goooo();
        cout<<'\n';
    }
    return 0;
}
