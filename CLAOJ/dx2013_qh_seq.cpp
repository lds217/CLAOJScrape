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
#define task "SEQ"

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

void debug(auto a[],auto n)
{
	cout<<endl;
	FOR(i,1,n)
		cout<<a[i]<<' ';
	cout<<endl;
}


//main


//inspired by sangph from THPT NHT

long long n,k;
long long pre[56];

int digit(long long a)
{
	int cnt=0;
	while(a!=0)
	{
		cnt++;
		a/=10;
	}
	return cnt;
}

void prepare()
{
	mset(pre,0);
	FOR(i,1,55)
		pre[i]=pre[i-1]*2+digit(i);
//	debug(pre,n);
}

void input()
{
	cin>>n>>k;
}

char findd(int n,long long k)
{
	ll t=digit(n);
	if(k<=t)
		return to_string(n)[k-1];
	if(n<=55)
	{
		ll temp=(pre[n]+t)/2;
		if(k<=temp)	return findd(n-1,k-t);
		else	return findd(n-1,k-temp);
	}
	else
		return findd(n-1,k-t);		
}

void lds_go_goooo()
{
	prepare();
	if(n<=55)
		if(k>pre[n])	cout<<-1;
		else	cout<<findd(n,k);
	else
		cout<<findd(n,k);
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
