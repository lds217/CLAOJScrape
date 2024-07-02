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
const ll maxn=3*1e3+2;
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

char lim;int n;
string s[maxn];
void input()
{
	cin>>lim>>n;
//	lim-='a';
	FOR(i,1,n)	cin>>s[i];
}
bool ck[27][27];
vector<int> check[27];

void pre(string &s1,string &s2)
{
	FOR(i,0,min(s1.size(),s2.size())-1)
	if(s1[i]!=s2[i])
	{
		if(!ck[s1[i]-'a'][s2[i]-'a'])
			check[s2[i]-'a'].pb(s1[i]-'a'),ck[s1[i]-'a'][s2[i]-'a']=1;
		return;	
	}

}
bool vs[27];
int idx=0,res[27];
void dfs(int u)
{
	if(vs[u])	return;
	for(int v: check[u])
	{
		if(ck[u][v]&&ck[v][u])
		{
			cout<<"Impossible";
			exit(0);
		}
		if(ck[v][u])
			dfs(v);
	}
	res[++idx]=u;
	vs[u]	=1;
}

void lds_go_goooo()
{
	FOR(i,1,n-1)	pre(s[i],s[i+1]);
//	for(int i:check[0])	cout<<i<<' ';
	//cout<<endl;
	FOR(i,0,lim-'a')	dfs(i);
	FOR(i,1,idx)	cout<<(char)(res[i]+'a');
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
