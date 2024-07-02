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
#define task ""

using namespace std;
typedef int64_t ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
const ll maxn=250+5;
const ll MOD=1e9+3;
const ll base=31;
const ll inf=1e18;


bool maximize(ll &A, ll B)
{
    return A<B ? A=B, true : false;
}

bool minimize(ll &A, ll B)
{
    return A>B ? A=B, true : false;
}

        // Main Function //
int moveX[]={1,-1,0,0};
int moveY[]={0,0,-1,1};
int R,C;
string a[maxn];
bool d[maxn][maxn];
int o=0,vv=0,fo=0,fv=0;
void bfs(int sx, int sy)
{
	queue <ii> q;
	q.push({sx,sy});
	d[sx][sy]=1;
	if(a[sx][sy]=='o')
        o++;
    if(a[sx][sy]=='v')
        vv++;
	while(!q.empty())
	{
		int x=q.front().fi;
		int y=q.front().se;
		q.pop();
		for(int i=0;i<4;i++)
		{
			int u=x+moveX[i];
			int v=y+moveY[i];
			if(u>R||v>C||u<1||v<1)
				continue;
			if(a[u][v]!='#'&&d[u][v]==0)
			{
				d[u][v]=1;
				q.push({u,v});
				if(a[u][v]=='o')
					o++;
                if(a[u][v]=='v')
                    vv++;
			}
		}
	}
//	cout<<o<<' '<<vv<<endl;
}

void input()
{
    cin>>R>>C;
    FOR(i,1,R)
    {
    	cin>>a[i];
    	a[i]=' '+a[i];
    }
}


void solve()
{
    FOR(i,1,R)
    	FOR(j,1,C)
    		if(d[i][j]==0&&a[i][j]!='#')
    		{
    			bfs(i,j);
    			if(o>vv)
    				fo+=o;
    			else
    				fv+=vv;
    			o=vv=0;
    		}
    		cout<<fo<<' '<<fv;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
   // freopen(task".INP", "r", stdin);
   // freopen(task".OUT", "w", stdout);
    ll test_case=1; //cin>>test_case;
    while(test_case--)
    {
        input(), solve();
        cout<<'\n';
    }
    return 0;
}

//for storage only
