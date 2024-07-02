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

bool maximize(int &A, int B)
{
    return A<B ? A=B, true : false;
}

bool minimize(int &A, int B)
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

ll n,q,m;
bool occ[100][50];
bool avoid[100][50];
int cur=-1e9;
int ans=1e9;
vector <int> T[100];

bool check(int teacher,int course)
{
	for(int v: T[teacher])	if(avoid[course][v]||avoid[v][course])	return 0;
	return 1;
}
bool chosen[100];

void Try(int course=1)
{
	static vector<int> d (100,0);
	if(course>n)
	{
		minimize(ans,cur);	
		return;
	}
	
	FOR(teacher,1,m)
		if(occ[teacher][course]&&check(teacher,course))
		{
			T[teacher].pb(course);
			d[course]=cur;
			maximize(cur,(int)T[teacher].size());
			if(cur<ans)	Try(course+1);
			T[teacher].pop_back();
			cur=d[course];
		}
}

void input()
{
	cin>>m>>n;
	FOR(i,1,m)
	{
		int k;
		cin>>k;
		while(k--)
		{
			int tmp;
			cin>>tmp;
			occ[i][tmp]=1;
		}
	}
	cin>>q;
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		avoid[x][y]=avoid[y][x]=1;
	}
	
}
void lds_go_goooo()
{
	Try();
	cout<<ans;
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
Test case--------------------------------------------
2 3
2 1 2
3 1 3 2
1
1 3
1




*/
