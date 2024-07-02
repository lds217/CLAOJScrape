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
#define int long long
struct lp{
	long long x,y;
} a[maxn];

long long n;

void input()
{
	cin>>n;
	FOR(i,0,n-1)
	{
		cin>>a[i].x>>a[i].y;
	}
}

bool direction(lp &A,lp &B, lp &C)
{
	return 1LL * (B.x - A.x) * (C.y - A.y) - 1LL * (C.x - A.x) * (B.y - A.y) > 0;
}

bool dc(lp &A,lp &B, lp &C)
{
	return 1LL * (B.x - A.x) * (C.y - A.y) - 1LL * (C.x - A.x) * (B.y - A.y) == 0;
}



void lds_go_goooo()
{
	vector <lp> hull;

	sort(a,a+n,[](lp a,lp b)
	{
		if(a.y==b.y)	
			return a.x<b.x;
		return a.y<b.y;
	});
	hull.pb(a[0]);
	FOR(i,1,n-1)
	{
		if(a[i].x==a[i-1].x&&a[i].y==a[i-1].y)	continue;
		while(hull.size()>=2&&direction(hull[hull.size()-2],hull.back(),a[i]))
			hull.pop_back();
		hull.pb(a[i]);
	}
	
	FORD(i,n-2,0)
	{
		if(a[i].x==a[i+1].x&&a[i].y==a[i+1].y)	continue;
		while(hull.size()>=2&&direction(hull[hull.size()-2],hull.back(),a[i]))
			hull.pop_back();
		hull.pb(a[i]);
	}
	int cnt=0;
	FOR(i,0,hull.size()-2)
		if(i==0||i==hull.size()-1||!dc(hull[i-1],hull[i],hull[i+1]))
			cnt++;
	cout<<cnt<<"\n";
	long long area=0;
	hull.pb(hull[0]);
	FOR(i,0,hull.size()-2)
		area+=(hull[i].x-hull[i+1].x)*(hull[i].y+hull[i+1].y);
	if(area%2==0)
		cout<<abs(area/2)<<".0"<<"\n";
	else
		cout<<abs(area/2)<<".5"<<"\n";
	hull.pop_back();
	reverse(ALL(hull));
	
	FOR(i,0,hull.size()-2)
		if(i==0||i==hull.size()-1||!dc(hull[i-1],hull[i],hull[i+1]))
		cout<<hull[i].x<<' '<<hull[i].y<<"\n";
	
	
}

signed main()
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
