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
const ll MOD=1000000003;
const ll MOD1=1000000011;
const int base = 31;
const int base1 = 71;
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



//main

long long POWW[maxn],hashT[maxn],POWW1[maxn],hashT1[maxn];
pair<long long,long long> a[maxn];
int n;
string str;

void input()
{
	cin>>n>>str;
	str=' '+str;
}

void prepare()
{
	POWW[0]=1;
	POWW1[0]=1;
	FOR(i,1,n)
	{
		POWW[i]=(POWW[i-1]*base)%MOD;
		hashT[i]=(hashT[i-1]*base+str[i]-'a'+1)%MOD;
		POWW1[i]=(POWW1[i-1]*base1)%MOD1;
		hashT1[i]=(hashT1[i-1]*base1+str[i]-'a'+1)%MOD1;
	}
	
}

long long gethashT(long i, long j)
{
	return(hashT[j]-hashT[i-1]*POWW[j-i+1]+MOD*MOD)%MOD;
}

long long gethashT1(long i, long j)
{
	return(hashT1[j]-hashT1[i-1]*POWW1[j-i+1]+MOD1*MOD1)%MOD1;
}

bool check(int g)
{
	
	FOR(i,1,n-g+1)
	{
		a[i-1].fi=gethashT(i,i+g-1);
		a[i-1].se=gethashT1(i,i+g-1);
	}
	sort(a,a+n-g+1);
	int cnt=0;
	FOR(i,1,n-g+1)
		if(a[i].fi==a[i-1].fi&&a[i].se==a[i-1].se)
	return 1;
	return 0;
}

void solve()
{
	prepare();
	int r=n,l=0;
	while(r>=l)
	{
		int mid=(r+l)/2;
		if(check(mid))
			l=mid+1;
		else
			r=mid-1;
	}
	cout<<r;
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
