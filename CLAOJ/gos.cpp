// Template //
#include <bits/stdc++.h>
#define FOR(i, a, b) for(ll i=a, _b=b; i<=_b; i++)
#define FORD(i, a, b) for(ll i=a, _b=b; i>=_b; i--)
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define mp make_pair
#define fi x1
#define se y1
#define mset(a, b) memset(a, b, sizeof(a))
#define MASK(i) (1LL<<(i))
#define BIT(x, i) (((x)>>(i))&1)
#define task "GOS"
 
using namespace std;
typedef int64_t ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
const ll maxn=1e6+5;
const ll mod=1e9+7;
const ll LOG=log2(maxn)+2;
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
    ll tmp=POW(a, b/2) % mod;
    return b%2==0 ? (tmp*tmp)%mod : (tmp*tmp*a) % mod;
}

//end of Template//
struct Point
{
	int x1,y1;
};
int N;
Point l[1001],c[1001];
vector <int> K[1001];

int value[1001];

Point findR(Point center, Point edge)
{
	Point r;
	r.fi=center.fi*2 - edge.fi;
	r.se=center.se*2 - edge.se;
	return r;
}

void dfs(int u)
{
	for(int i : K[u])
		if(value[i]>value[u]+1)
		{
			value[i]=value[u]+1;
			dfs(i);
		}
}

bool intersect(Point l1, Point r1, Point l2, Point r2)
{
	if (l1.fi == r1.fi || l1.se == r1.se || r2.fi == l2.fi || l2.se == r2.se)
        return false;
    if(l1.fi>=r2.fi||l2.fi >= r1.fi)
    	return false;
    if (r1.se >= l2.se || r2.se >= l1.se)
        return false;
    return true;
}

int main()
{
	freopen ("GOS.inp", "r", stdin);
    freopen ("GOS.out", "w", stdout);
	cin>>N;
	FOR(i,1,N)
	{
		cin>>c[i].fi>>c[i].se>>l[i].fi>>l[i].se;
	}
	
	FOR(i,1,N)
	{
		FOR(j,i+1,N)
		{
			Point l1=l[i];
			Point l2=l[j];
			Point r1=findR(c[i],l[i]);
			Point r2=findR(c[j],l[j]);
			if(l1.se<r1.se)
				swap(l1.se,r1.se);
			if(l1.fi>r1.fi)
				swap(l1.fi,r1.fi);
			if(l2.se<r2.se)
				swap(l2.se,r2.se);
			if(l2.fi>r2.fi)
				swap(l2.fi,r2.fi);
		//	cout<<l1.fi<<" "<<l1.se<<' '<<r1.fi<<' '<<r1.se<<endl;
			if(intersect(l1,r1,l2,r2))
				K[i].push_back(j);		
		}
	}
	FOR(i,1,N)	value[i]=1e9;
	value[1]=0;
	dfs(1);
	if(value[N]!=1e9)
		cout<<value[N];
	else
		cout<<-1;
}
