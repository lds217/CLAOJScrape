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
#define task "duongdi"

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


int n;
vector <ii> k[25000];
int val[1000];
int trace[10000];
int p,q;
void input()
{
	cin>>n;
	FOR(i,1,n)
	{
		val[i]=1e9;
		FOR(j,1,n)
		{
			int u;
			cin>>u;
			if(u!=0)
			k[i].push_back({j,u});
		}
	}
	cin>>p>>q;
}

void bfs(int st)
{
	queue <ii> q;
	val[st]=0;
	q.push({st,0});
	while(!q.empty())
	{
		int u=q.front().fi;
		int du=q.front().se;
		q.pop();
		if(du!=val[u])	continue;
		for(ii o:k[u])
		{
			int v=o.fi;
			int dv=o.se;
			if(du+dv<val[v])
			{
				trace[v]=u;
				val[v]=du+dv;
				q.push({v,val[v]});
			}
		}
	}
	
}


void lds_go_goooo()
{
	bfs(p);
	if(val[q]==1e9)
	{
		cout<<-1;
		return;
	}
	cout<<val[q]<<endl;
	long long tmp=q;
	stack <int> ans;
	while(tmp!=p)
	{
		ans.push(tmp);
		tmp=trace[tmp];
	}
	cout<<p<<' ';
	while(!ans.empty())
	{
		cout<<ans.top()<<' ';
		ans.pop();
	}
	
}

int main()
{
 	ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen(task".INP", "r", stdin);
    //freopen(task".out", "w", stdout);
    ll test_case=1; //cin>>test_case;
    while(test_case--)
    {
        input(), lds_go_goooo();
        cout<<'\n';
    }
    return 0;
}
