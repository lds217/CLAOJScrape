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
const ll maxn = 5e5 + 100;
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
#define int ll 
int n,m,scc;
vector <int> G[maxn],adj[maxn];
vector <ii> edge;
int comp[maxn];
stack <int> st;

void input()
{
    cin>>n>>m;
    FOR(i,1,m)
    {
        int u,v;
        cin>>u>>v;
        G[u].pb(v);
        edge.pb({u,v});
    }
}
int firstofscc[maxn];
int low[maxn],num[maxn],timer,deleted[maxn];
void tarjan(int u)
{
    low[u]=num[u]=++timer;
    st.push(u);
    for(int v: G[u])
    {
        if(deleted[v])  continue;
        if(!num[v])
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else
            low[u]=min(low[u],num[v]);
    }
    if(num[u]==low[u])
    {
        scc++;
        int v;
        firstofscc[scc]=st.top();
        do{
            
            v=st.top();
            comp[v]=scc;
            deleted[v]=1;
            st.pop();
        }
        while(v!=u);
    }
}


bool vs[maxn];
int match[maxn];

int dfs(int u)
{
    vs[u]=1;
    if(adj[u].size()==0)
        return u;
    for(int v: adj[u])
        if(!vs[v])
        {
            int ret=dfs(v);
            if(~ret) return ret;
        }
    
    return -1;
}
//who scc 

int in[maxn],out[maxn];
void lds_go_goooo()
{
    mset(match,-1);
    FOR(i,1,n)
        if(!num[i])
            tarjan(i);
    n=scc;
    for(ii i: edge)
    {
        int u=i.fi;
        int v=i.se;
        if(comp[u]!=comp[v])
        {
            adj[comp[u]].pb(comp[v]);
            in[comp[v]]++;
        }
    }
    int ans=0;
    // FOR(i,1,n)
        // cout<<i<<':'<<in[i]<<endl;
    //cout<<scc<<endl;
    // FOR(i,1,n)
    // {
    //     if(adj[i].size())
    //     {
    //         cout<<i<<endl;
    //         for(int v:adj[i])
    //             cout<<v<<' ';
    //         cout<<endl;
    //     }
    // }
    
    FOR(i,1,n)
    {
        if(in[i])   continue;
        if(vs[i])   continue;
        match[i]=dfs(i);
        if(match[i]!=-1)
            match[match[i]]=i;
    }
    //cout<<match[2]<<endl;
    if(scc==1)
    {
        cout<<0;
        return;
    }
    vector <int> I,O;
    FOR(i,1,n)
    {
        if(in[i])   continue;
        if(match[i]==-1)    continue;
        I.pb(firstofscc[i]);
        O.pb(firstofscc[match[i]]);
    }
    //cout<<match[1]<<' '<<1<<endl;
    FOR(i,1,n)
    {
        if(match[i]!=-1)continue;
       // cout<<"SIUUU";
        if(in[i]==0)   
            I.pb(firstofscc[i]);
        if(adj[i].size()==0)
            O.pb(firstofscc[i]);
    }
    // cout<<I.size();
    // cout<<endl;
    // cout<<O.size()<<endl;
    while(I.size()<O.size())
       I.pb(I.front());
    while(I.size()>O.size())
       O.pb(O.front());
    n=I.size();
    cout<<I.size()<<endl;
    FOR(i,0,I.size()-1)
        cout<<O[(i+1)%n]<<' '<<I[i]<<endl;
}

signed  main()
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
