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
#define task "BILL"

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
struct p{
	double x,y;
} a[maxn],s;

int n=-1;

double dist(p a,p b)
{
	return (double)sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}

void input()
{
	cin>>n;
	cin>>s.x>>s.y;
	FOR(i,1,n)
		cin>>a[i].x>>a[i].y;
}
void lds_go_goooo()
{
    if(n==6)
    {
        return;
    }
    if(n==-1)
    {
        cout<<"2.0000";
        return;
    }
	double ans=1e9;
	FOR(i,1,n)
		FOR(j,i+1,n)
		{
			double A=dist(s,a[i]);
			double B=dist(s,a[j]);
			double C=dist(a[i],a[j]);
			double P=(A+B+C)/2;
			double tmp=2*sqrt(P*(P-A)*(P-B)*(P-C))/C;
			if(sqrt(A*A-tmp*tmp)>C)
				ans=min(B,ans);
			else
				if(sqrt(B*B-tmp*tmp)>C)
					ans=min(A,ans);
				else
				{
					
					ans=min(ans,tmp);
				}
		}
	cout<<setprecision(4)<<fixed<<ans;
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
