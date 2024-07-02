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

int n,a[21],ans=1e9;
vector <int> k[4];
vector<int> v1,v2,v3;
int sum1=0,sum2=0,sum3=0;
void finddiff(int pos)
{
	if(pos>n)
	{
		if(sum1==0||sum2==0||sum3==0)
			return;
		if(max({sum1,sum2,sum3})-min({sum1,sum2,sum3})<ans)
		{
    		k[1].clear();
			k[2].clear();
			k[3].clear();
			ans= max({sum1,sum2,sum3})-min({sum1,sum2,sum3});
			for(int i: v1) k[1].pb(i);
			for(int i: v2) k[2].pb(i);
			for(int i: v3) k[3].pb(i);
		}
		return;
	}


			
	v1.pb(pos);
	sum1+=a[pos];
	finddiff(pos+1);
	sum1-=a[pos];
	v1.pop_back();

	if(v1.back()<pos&&!v1.empty())
	{
		v2.pb(pos);
		sum2+=a[pos];
		finddiff(pos+1);
		sum2-=a[pos];
		v2.pop_back();
		if(v1.back()<pos&&v2.back()<pos&&!v2.empty())
		{
			v3.pb(pos);
			sum3+=a[pos];
			finddiff(pos+1);
			sum3-=a[pos];
			v3.pop_back();
		}
	}
	
}

void input()
{
	cin>>n;
	FOR(i,1,n)	cin>>a[i];
}

void lds_go_goooo()
{
	//sort(a+1,a+n+1);
	//FOR(i,1,n) cout<<a[i]<<' ';
	cout<<endl;
	

	finddiff(1);
	cout<<ans<<endl;
	
	FOR(i,1,3)
	{
		sort(ALL(k[i]));
	
		for(int j:k[i])
			cout<<j<<" ";
		cout<<endl;
	}
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
