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
const ll maxn=1e5+2;
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

struct nlp{
	double x,y,id;
} a[maxn];

double ans1,ans2,final=1E20;
int n;

bool cmp_x(const nlp &a,const nlp &b)
{
	return a.x<b.x;
}

bool cmp_y(const nlp &a,const nlp &b)
{
	return a.y<b.y;
}

void upd(const nlp &a,const nlp &b)
{
	 double dist = sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
	 if(dist<final)
	 {
	 	final=dist;
	 	ans1=a.id;
	 	ans2=b.id;
	 }
}

void find(int l,int r)
{
	if(r<=l)	return;
	
	if(r==l+1)
	{
		upd(a[l],a[r]);
		if(!cmp_y(a[l],a[r]))swap(a[l],a[r]);
		return;
	}

	int m=(l+r)/2;
	double tt=a[m].x;
	find(l,m);
	find(m+1,r);	static nlp t[maxn]; 
	merge(a+l, a+m+1, a+m+1, a+r+1, t, cmp_y); copy(t, t+r-l+1, a+l);
	int cnt=0;
	FOR(i,l,r)
		if(abs(a[i].x-tt)<final)
		{
			for (int j=cnt-1; j>=0 && t[j].y > a[i].y-final; j--)
            	upd(a[i], t[j]);
            t[cnt++]=a[i];
		}
		
}

void input()
{
	cin>>n;
	FOR(i,0,n-1)	cin>>a[i].x>>a[i].y,a[i].id=i;
}
void lds_go_goooo()
{
	sort(a,a+n,cmp_x);
	find(0,n-1);
	if(ans1>ans2)
		swap(ans1,ans2);
	cout<<ans1<<' '<<ans2<<' '<<setprecision(6)<<fixed<<final;
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

/*


 d8b d8b
888888888
`Y88888P'       "Heart"
 `Y888P'      Le Thanh Dat
  `Y8P'
   `Y'
   
*/
