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
const ll maxn=3*1e3;
const ll mod=26051968;
const ll inf=1e18;


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
        // Main Function //
int n,dp[maxn][maxn],p[maxn];
string str;
vector <int> K[maxn];

void input()
{
    cin>>n>>str;
    str="#"+str;
    FOR(i,1,n-1)
    {
        int u,v;
        cin>>u>>v;
        K[u].pb(v);
        K[v].pb(u);
    }
    mset(dp,-1);
}

int dfs2(int i, int j)
{
    int &res=dp[i][j];
    if(res!=-1) return res;
    if(str[i]==str[j])res=dfs2(p[i],p[j])+2;
    res=max(res,max(dfs2(i,p[j]),dfs2(p[i],j)));
    return dp[j][i]=res;
}

void dfs1(int u, int par)
{
    p[u]=par;
    int P= par,last=u;
    while(P!=0)
    {
        dp[P][u]=0;
        if(str[P]==str[u]) dp[P][u]=max(0,dp[last][p[u]])+2;
        dp[P][u]=max(dp[P][u],max(dp[last][u],dp[P][p[u]]));
        dp[u][P]=dp[P][u];
        last=P,P=p[P];
    }
    for( int v : K[u])  if(v!=par)  dfs1(v,u);
}

void solve()
{
    FOR(i,0,n) dp[i][i]=1;
    dfs1(1,0);
    int res=0;
    FOR(i,1,n)
        FOR(j,i,n)
            res=max(res,dfs2(i,j));
    cout<<res;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen(task".INP", "r", stdin);
   // freopen(task".OUT", "w", stdout);
    ll test_case=1; //cin>>test_case;
    while(test_case--)
    {
        input(), solve();
        cout<<'\n';
    }
    return 0;
}
