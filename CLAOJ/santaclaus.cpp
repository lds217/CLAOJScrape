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
const ll maxn=2*1e3+2;
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
char a[maxn][maxn];
ll val[maxn][maxn];
int x,y;
ll front,back,ans=0;

void input()
{
	cin>>n>>m;
	FOR(i,1,n)
		FOR(j,1,m)
		{
			cin>>a[i][j];
			if(a[i][j]=='A')
				a[i][j]=='.',x=i,y=j;
				
		}
}

void bfs(int sx,int sy)
{
	
	mset(val,0x3f);
	queue <ii> q;
	q.push({sx,sy});
	val[sx][sy]=0;
	while(!q.empty())
	{
		int X=q.front().fi;
		int Y=q.front().se;
		q.pop();
		FOR(i,0,3)
		{
			int nX=X+moveX[i];
			int nY=Y+moveY[i];
			if(nX<=0||nY<=0||nX>n||nY>m)	continue;
			if(val[nX][nY]>val[X][Y]+1&&a[nX][nY]!='#')
			{
				val[nX][nY]=val[X][Y]+1;
				q.push({nX,nY});
			}
		}
	}
}

void lds_go_goooo()
{
	bfs(x,y);
	if(val[n][m]+val[1][1]>1e9)
		cout<<-1;
	else
		cout<<val[n][m]+val[1][1]+1;
}

int main()
{
 	//ios_base::sync_with_stdio(false);
    //cin.tie(0);
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
