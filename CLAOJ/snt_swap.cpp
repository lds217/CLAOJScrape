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
#define task "SWAP"

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

bool eratos[maxn];
int a[maxn],pos[maxn];
int n;
void pre()
{
	eratos[1]=1;
	for(int i=2;i*i<=n;i++)
		if(eratos[i]==0)
			for(int j=i*i;j<=n;j+=i)
				eratos[j]=1;
}

void input()
{
	cin>>n;
	FOR(i,1,n)
	{
		cin>>a[i];
		pos[a[i]]=i;
	}
}
void lds_go_goooo()
{
	pre();
	vector <ii> ans;
	FOR(i,1,n)
	{
		int j=pos[i];
		while(j>i)
		{
			int t=i;
			while(eratos[j-t+1])
				t++;
			ans.pb({t,j});
			pos[a[j]]=t;
			pos[a[t]]=j;
			swap(a[j],a[t]);
			j=t;
			
		}
	}
	if(ans.size()>5*n)
		cout<<0;
	else
	{
		cout<<ans.size()<<endl;
		for(ii i:ans)
			cout<<i.fi<<' '<<i.se<<endl;
	}
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
