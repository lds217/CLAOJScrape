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
bool yes=0;
int n,m,sx,sy;
char a[252][252];
long long val[252][252];
map <ii,ii> trace;

void input()
{
	cin>>n>>m;
	FOR(i,1,n)
		FOR(j,1,m)
		{
			cin>>a[i][j];
			if(a[i][j]=='E')
				sx=i,sy=j;
		}
}

void bfs(int xt,int yt)
{
	mset(val,0x3f);
	queue <ii> q;
	val[xt][yt]=1;
	q.push({xt,yt});
	while(!q.empty())
	{
		long long x=q.front().fi;
		long long y=q.front().se;
		q.pop();
		FOR(i,0,3)
		{
			long long u=x+moveX[i];
			long long v=y+moveY[i];
			
			if(u<=0||u>n||v<=0||v>m)
				continue;
			if(a[u][v]=='O'&&val[u][v]>val[x][y]+1)
			{
				trace[{u,v}]={x,y};
				val[u][v]=val[x][y]+1;
				q.push({u,v});
				if(u==1||v==1||u==n||v==m)
				{
				    yes=1;
					cout<<val[u][v]<<endl;
					cout<<u<<' '<<v<<endl;
					long long i=0,j=0;
					while(a[i][j]!='E')
					{
					 	i=trace[{u,v}].fi;
						j=trace[{u,v}].se;
						cout<<i<<' '<<j<<endl;
						u=i,v=j;
					}
					
					return ;
				}
			}
		}
	}
	
}

void lds_go_goooo()
{
	bfs(sx,sy);
	if(yes==0)
	    cout<<-1;
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
       // cout<<'\n';
    }
    return 0;
}
