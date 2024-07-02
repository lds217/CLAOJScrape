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

struct point{
	ld x,y,z;
} A,a[maxn];

ll n,k;
void input()
{
	cin>>n;
	cin>>A.x>>A.y>>A.z;
	FOR(i,1,n)
		cin>>a[i].x>>a[i].y>>a[i].z;	
}


ld dist(point x, point y)
{
    return sqrt((x.x-y.x)*(x.x-y.x) + (x.y-y.y)*(x.y-y.y) + (x.z-y.z)*(x.z-y.z));
}


void lds_go_goooo()
{
	a[0]=a[n];
	a[n+1]=a[1];
	a[n+2]=a[2];
	a[n+3]=a[3];
	a[n+4]=a[4];
	ll ans=-1;
	FOR(i,1,n)
		if(abs(dist(a[i],a[i-1])-dist(a[i],a[i+1]))<1e-2&&abs(dist(a[i],a[i+1])-dist(a[i],a[i+2]))<1e-2&&abs(dist(a[i],a[i+2])-dist(a[i],a[i+3]))<1e-2&&abs(dist(a[i],a[i+3])-dist(a[i],a[i+4]))<1e-3)
		{
			ans=i;break;
		}
		cout<<setprecision(2)<<fixed<<dist(A,a[ans])-dist(a[ans],a[ans+1]);

//	cout<<ans;

			
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
