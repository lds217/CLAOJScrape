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
const ll maxn=2*1e6+2;
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
int vs[maxn],y[maxn];
vector <long long> k[maxn];
long long m,n,p;
bool eratos[maxn];

void pre_era()
{
	mset(eratos,0);
	eratos[0]=eratos[1]=1;
	for(int i=2;i*i<=2e6;i++)
		if(eratos[i]==0)
			for(int j=i*i;j<=2e6;j+=i)
				eratos[j]=1;
}
	int a[100001];
void input()
{
	pre_era();
	cin>>n;
	FOR(i,1,n)	cin>>a[i];
}


int t;

bool dfs(int i)
{
	if(vs[i]!=t)
		vs[i]=t;
	else
		return 0;
	for(int v:k[i])
		if(y[v]==0||dfs(y[v]))
		{
			y[v]=i;
			return 1;
		}
	return 0;
}

void lds_go_goooo()
{
	FOR(i,1,n)
		FOR(j,1,n)
			if(a[i]!=1&&a[j]!=1)
			if(eratos[a[i]+a[j]]==0)
					k[i].pb(j);
	FOR(i,1,n)
		FOR(j,1,n)	
			if(a[i]%2==1||a[j]!=1)	continue;
			else	if(!eratos[a[i]+a[j]])	k[i].pb(j),k[j].pb(i);
	ll cnt=0,tmp=0;
	FOR(i,1,n)
	{
		if(a[i]%2==1)	continue;
		t++;
		cnt+=dfs(i);
	}
	bool married[maxn];
	vector <ll> one;
	FOR(i,1,n)
	{
		if(y[i]==0)	continue;
		married[i]=1;
		married[y[i]]=1;
	}
	FOR(i,1,n)
	{
		if(!married[i]&&a[i]==1)
			one.pb(i),tmp++;			
	}
	cnt+=tmp/2;
	cout<<cnt<<endl;
	FOR(i, 0, (tmp/2)-1) cout<<one[i*2]<<' '<<one[i*2+1]<<'\n';
	FOR(i,1,n)
		if(y[i]!=0)
		cout<<i<<' '<<y[i]<<endl;
	
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

//Dont ask me why this code works, go ask Kieu Phat
