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
int prime[maxn];
void pre()
{
	for(int i=2;i*i<=maxn;i++)
		if(!prime[i])
			for(int j=i;j<=maxn;j+=i)
				prime[j]=i;
	FOR(i,1,2000001)
		if(!prime[i]) prime[i]=i;
}
ll n;
void input()
{
	cin>>n;
}

ii get(int x)
{
	int res=1,respow=1;
	while(x>1)
	{
		int div=prime[x];
		int cnt=0;
		while(x%div==0)
			x/=div,cnt++;
		res*=(cnt+1);
		respow*=(cnt*2+1);
	}
	return {res,respow};
}

void lds_go_goooo()
{
	ii leftover={0,0};
	int n1=n,n2=n+1,n3=n+2;
	int cnt=0;
	while(n1%2==0)
	{
		cnt++;
		n1/=2;
	}
	while(n3%2==0)
	{
		cnt++;
		n3/=2;
	}
	leftover={cnt+1,cnt*2+1};
//	cout<<leftover.fi<<' '<<leftover.se<<endl;
	auto s1=get(n1);
	auto s2=get(n2);
	auto s3=get(n3);
	cout<<(s1.se*s2.se*s3.se*leftover.se-1)/2-leftover.fi*s1.fi*s2.fi*s3.fi+1;
		

}

int main()
{
 	ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen(task".INP", "r", stdin);
    //freopen(task".OUT", "w", stdout);
    ll test_case=1; cin>>test_case;
    pre();
    while(test_case--)
    {
        input(), lds_go_goooo();
        cout<<'\n';
    }
    return 0;
}
