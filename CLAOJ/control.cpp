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
#define task "CONTROL"

using namespace std;
typedef int64_t ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
const ll maxn=2e5+2;
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
const ll offset=1e5;
vector <int> col[maxn],row[maxn];
int n,m;
string track;

void input()
{
	cin>>n>>m;
	col[0+offset].pb(0+offset);
	row[0+offset].pb(0+offset);
	FOR(i,1,n)
	{
		int u,v;
		cin>>u>>v;
		col[u+offset].pb(v+offset);
		row[v+offset].pb(u+offset);
	}
	cin>>track;
	//cout<<maxn;
	FOR(i,0,2e5)
	{
		if(col[i].size())
			sort(ALL(col[i]));
		if(row[i].size())
			sort(ALL(row[i]));
	}

}

void lds_go_goooo()
{
	int curx=0+offset,cury=0+offset;
	FOR(i,0,m-1)
	{
		if(track[i]=='R')
			curx=row[cury][upper_bound(ALL(row[cury]),curx)-row[cury].begin()];
		if(track[i]=='L')
			curx=row[cury][lower_bound(ALL(row[cury]),curx)-row[cury].begin()-1];
		if(track[i]=='U')
			cury=col[curx][upper_bound(ALL(col[curx]),cury)-col[curx].begin()];
		if(track[i]=='D')
			cury=col[curx][lower_bound(ALL(col[curx]),cury)-col[curx].begin()-1];
	}
	cout<<curx-offset<<' '<<cury-offset;
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
