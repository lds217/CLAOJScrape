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

int n,x;
int a[maxn];
void input()
{
	cin>>n>>x;
	FOR(i,1,n)
		cin>>a[i];
}

void lds_go_goooo()
{
	vector <int> adj;
	int fh=n/2;
	FOR(i,0,MASK(fh)-1)
	{
		int sum=0;
		FOR(j,0,fh-1)
			if(BIT(i,j))
				sum+=a[j+1];
		adj.pb(sum);
	}
	/*for(int i: adj)
		cout<<i<<' ';
	cout<<endl;*/
	vector <int> b;
	int sh=(n+1)/2;
	//cout<<sh;
	FOR(i,0,MASK(sh)-1)
	{
		int sum=0;
		FOR(j,0,sh-1)
			if(BIT(i,j))
				sum+=a[j+1+fh];
		b.pb(sum);
	}
	/*for(int i: b)
		cout<<i<<' ';
	cout<<endl;*/
	sort(ALL(b));
	int res=0;
	for(int i: adj)
		res+=(upper_bound(ALL(b),x-i)-b.begin())-(lower_bound(ALL(b),x-i)-b.begin());
	cout<<res;			
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
