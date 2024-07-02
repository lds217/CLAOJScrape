// Template //
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <unordered_set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <cmath>
#include <array>
#include <cassert>
#include <random>

#define FOR(i, a, b) for (ll i = a, _b = b; i <= _b; i++)
#define FORD(i, a, b) for (ll i = a, _b = b; i >= _b; i--)
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define mp make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)

using namespace std;
typedef int64_t ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
const ll maxn = 2e5 + 100;
const ll mod = 998244353;
const ll inf = 1e18;

const int moveX[] = {0, 0, 1, -1};
const int moveY[] = {-1, 1, 0, 0};

template <class T> bool minimize(T &a, T b) { if (a > b) { a = b; return true; } return false;}

template <class T> bool maximize(T &a, T b) { if (a < b) { a = b; return true; } return false;}

ll POW(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll tmp = POW(a, b / 2);
    return b % 2 == 0 ? (tmp * tmp) % mod : ((tmp * tmp) % mod * a) % mod;
}

// End of template//
int n,m;
int comp[maxn],d[maxn],low[maxn],timer,lvl[maxn],f[maxn];
bool joint[maxn];
int p[maxn][25];
vector<int> G[maxn];
void input()
{
    cin>>n>>m;
    FOR(i,1,m)
    {
        int u,v;
        cin>>u>>v;
        G[u].pb(v);
        G[v].pb(u);
    }

}
int curr=0;

void dfs(int u,int c)
{
    d[u]=low[u]=++timer; comp[u]=c;
    int nchild=0;
    for(int v:G[u])
        if(d[v]==-1)
        {
            lvl[v]=lvl[u]+1;
            p[v][0]=u;
            ++nchild;
            dfs(v,c);
            low[u]=min(low[u],low[v]);
            if(low[v]>=d[u]||(p[u][0]==-1&&nchild>=2))
                joint[u]=1;
        }
        else
        {
            if(v!=p[u][0])
                low[u]=min(low[u],d[v]);
        }
    f[u]=timer++;
}


void init()
{
    mset(d,-1);
    mset(p,-1);
    int cur=0;
    FOR(i,1,n)
        if(d[i]==-1)
            dfs(i,++cur);
    for(int i = 1; i<=22;i++)
        FOR(j,1,n)   // if(p[j][i-1]!=-1)
            p[j][i]=p[p[j][i-1]][i-1];
}

bool isCon(int u,int v)
{
    return d[u]>=d[v]&&f[u]<=f[v];
}

bool query1(int x,int y,int u, int v)
{
    if(comp[x]!=comp[y]) return false;
    if(comp[x]!=comp[u])    return true;
    if(lvl[v]<lvl[u])swap(u,v);
    if(low[v]<d[v]) return  true;
    return !(isCon(x,v)^isCon(y,v));
}

int jump(int u,int val)
{
    FOR(i,0,22)
        if(val&MASK(i))
            u=p[u][i];
    return u;
}

bool query2(int x,int y,int u)
{
    if(comp[x]!=comp[y]) return false;
    if(comp[x]!=comp[u])    return true;
    if(!joint[u]) return true;
    if(!isCon(x, u) && !isCon(y, u)) return true;
    if(!isCon(x,u))swap(x,y);
    int px=jump(x,lvl[x]-lvl[u]-1);
    if(isCon(y,u))
    {
        int py=jump(y,lvl[y]-lvl[u]-1);
        return(px==py||(low[px]<d[u]&&low[py]<d[u]));  
    }
    return low[px]<d[u];
}

void lds_go_goooo()
{
    init();
    int q;cin>>q;
    while(q--)
    {
        int type;cin>>type;
        if(type==1)
        {
            int x,y,u,v;
            cin>>x>>y>>u>>v;
            if(query1(x,y,u,v))
                cout<<"yes";
            else   
                cout<<"no";
            cout<<endl;
        }
        else
        {
            int x,y,u;
            cin>>x>>y>>u;
            if(query2(x,y,u))
                cout<<"yes";
            else   
                cout<<"no";
            cout<<endl; 
        }

    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #define task "rbtree"
    // freopen(task".INP", "r", stdin);
    // freopen(task".OUT", "w", stdout);
    // int sub=1;
    // cin>>sub;
    ll test_case = 1; // cin>>test_case;
    while (test_case--)
    {
        input();
        lds_go_goooo();
        cout << '\n';
    }
    return 0;
}
