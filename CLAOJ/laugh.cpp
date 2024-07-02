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
const ll maxn=26*1e4+2;
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

int n,m;
int child[maxn][26];
bool oke [maxn];
long long f[maxn],res=0;
int cnt=0;
string str;

void add(string s)
{
	int par=0;
	for(char c:s)
	{
		if(child[par][c-'a']==0)	child[par][c-'a'] =++cnt	;
		par=child[par][c-'a'];
	}
	oke[par]=1;
}


void input()
{
	cin>>n>>str;
	while(n--)
	{
		string s;
		cin>>s;
		reverse(s.begin(),s.end());
		add(s);
	}
	str='.'+str;
}
void solve()
{
	FOR(i,1,str.size()-1)
	{
		int par=0;
		for(int j=i;;j--)
		{
			if(child[par][str[j]-'a']==0)break;
			par=child[par][str[j]-'a'];
			if(oke[par]) f[i]=max(f[i],f[j-1]+i-j+1);
		}
		res=max(res,f[i]);
	}
	cout<<res;
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
        input(), solve();
        cout<<'\n';
    }
    return 0;
}
