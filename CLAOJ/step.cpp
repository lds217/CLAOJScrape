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
#define task "STEP"

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

int n,k;
vector <pair<long double,long long>> v;

void input()
{
	cin>>n>>k;
	FOR(i,1,n)
	{
		int m,c;
		cin>>m>>c;
		int x[200005],y[200005];
		FOR(i,1,m)
			cin>>x[i]>>y[i];
		x[m+1]=x[1],y[m+1]=y[1];
		long double area=0;
		FOR(i,1,m)
			area+=(x[i]-x[i+1])*(y[i]+y[i+1]);
		area=area*1/2;
		area=abs(area);
	//	cout<<area<<endl;
		v.push_back({area,c});
	}
	sort(ALL(v));
}

long double replace(long double area, int c)
{
	long long  pre[2000005];
	pre[0]=(v[0].se!=c);
	FOR(i,1,n-1)
		pre[i]=pre[i-1] + (v[i].se!=c);
	long double z=0.0;
	int r=0,l=0;
	long double curr=0,res=0;
	while(r<n)
	{
		curr+=v[r].fi;
			while(pre[r]-(l==0.0?0.0:pre[l-1])>k)
			{
				curr-=v[l].fi;
				l++;
			}
		res=max(curr,res);
		r++;
	}	
	return res;
}

void solve()
{
	FORD(i,n-1,1)
		v[i].fi-=v[i-1].fi;
//	FOR(i,0,n-1)
//		cout<<v[i].fi<<' '<<v[i].se<<endl;
 long double res=0;
	FOR(i,0,n-1)
		res=max(res,replace(v[i].fi,v[i].se));
	cout<<setprecision(1)<<fixed<<res;
		
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
        input(), solve();
        cout<<'\n';
    }
    return 0;
}
