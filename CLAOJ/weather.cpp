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
#define int ll
struct area{
	int type,l,b,r,t;
};
//sun -1,rain 1
        // Main Function //
area k[maxn];
int h,w,n,d,dp[6005][6005];
bool vs[6005][6005];
vector<int> X,Y;
void input()
{
	cin>>h>>w>>n>>d;
	X.pb(1),X.pb(w+1);
	Y.pb(1),Y.pb(h+1);
	FOR(i,1,n)
	{
		string tmp;
		cin>>tmp;
		if(tmp=="mild")
			continue;
		if(tmp=="sun")
			k[i].type=-1;
		else
			k[i].type=1;
		cin>>k[i].l>>k[i].b>>k[i].r>>k[i].t;
		X.pb(k[i].l);
		X.pb(k[i].r+1);
		Y.pb(k[i].b);
		Y.pb(k[i].t+1);
	}
}

ll bfs(int sx,int sy)
{
	queue<ii> q;
	q.push({sx,sy});
	vs[sx][sy]=1;
	while(!q.empty())
	{
		int x=q.front().fi;
		int y=q.front().se;
		q.pop();
		FOR(i,0,3)
		{
			int dx=x+moveX[i];
			int dy=y+moveY[i];
			if(dx>=Y.size()-1||dx<0||dy>=X.size()-1||dy<0)
				continue;
			if(vs[dx][dy]==0&&abs(dp[dx][dy])<=d)
			{
				q.push({dx,dy});
				vs[dx][dy]=1;
			}
		}
	}
	return 1;
}

int getX(int x)
{
	int pos=lower_bound(ALL(X),x)-X.begin();
	return pos;
}

int getY(int x)
{
	int pos=lower_bound(ALL(Y),x)-Y.begin();
	return pos;
}

ll get(int i,int j)
{
	return (Y[i+1]-Y[i])*(X[j+1]-X[j]);
}

void solve()
{
	mset(vs,0);
	sort(ALL(X));
	sort(ALL(Y));
	X.resize(unique(ALL(X))-X.begin());
	Y.resize(unique(ALL(Y))-Y.begin());

	mset(dp,0);
	FOR(i,1,n)	
		if(k[i].type!=0)
		{
			int type=k[i].type;
			int l=getX(k[i].l);
			int r=getX(k[i].r+1);
			int t=getY(k[i].t+1);
			int b=getY(k[i].b);
			dp[t][l]-=type;
			dp[t][r]+=type;
			dp[b][l]+=type;
			dp[b][r]-=type;
		}
	
	FOR(i,0,Y.size())
		FOR(j,0,X.size())
		{
			if(i>0)	dp[i][j]+=dp[i-1][j];
			if(j>0)	dp[i][j]+=dp[i][j-1];
			if(i&&j)	dp[i][j]-=dp[i-1][j-1];
		}
/*	cout<<"X: ";
	for(int i:X)	cout<<i<<' ';
	cout<<endl;
	cout<<"Y: ";
	for(int i:Y)	cout<<i<<' ';
	cout<<endl;
	cout<<get(2,2)<<endl;
	FOR(i,0,Y.size()-2)
	{
		FOR(j,0,X.size()-2)	cout<<dp[i][j]<<' ';
		cout<<endl;
	}
	cout<<get(2,2)<<endl;*/
	ll cnt=0,fn=0;
	FOR(i,0,Y.size()-2)
		FOR(j,0,X.size()-2)
		{
			if(abs(dp[i][j])<=d)
			{
				cnt+=get(i,j);
				if(vs[i][j]==0)
					fn+=bfs(i,j);
			}
		}
	cout<<cnt<<' '<<fn;
}

signed main()
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
