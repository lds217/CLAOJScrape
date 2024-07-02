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
#define task "DUONGTRUYEN"

using namespace std;
typedef int32_t ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
const ll maxn=2e2;
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
struct lds{
    ll u, v, w;
    bool operator < (const lds &a) const {
        return w < a.w;
    }
};

ll n,m;
ll r[maxn]; 
int d[201][201];
multiset<lds> s;

int get(int u)
{
    return (r[u]?r[u]=get(r[u]):u);
}

void input()
{
    mset(d,0x3f);
    cin>>n>>m;
    FOR(i,1,n-1)
    {
        int u,v,w;
        cin>>u>>v>>w;
        if(d[u][v]>w){
		
        s.insert({u,v,w});d[u][v]=w;
    }
    }
}


void lds_go_goooo()
{
   /*for(auto [u,v,w]:s)
    cout<<u<<' '<<v<<' '<<w<<endl;*/
     string type;
    while(m--)
    {
        cin>>type;
        if(type[0]=='A')
        {
            ll u,v,w;
            cin>>u>>v>>w;
          //  n=max({n,u,v});
          if(d[u][v]>w)
          {
            s.insert({u,v,w});
            d[u][v]=w;
        }
        }
        else
        {
            memset(r,0,(n) * sizeof(int));
            ll cnt=0,res=0;   
            for(auto a:s)
            {
               int ru=get(a.u);
                int rv=get(a.v);
                if(ru!=rv)
                {
                    cnt++;
                    res+=a.w;
                    if(ru<rv)
                    r[ru]=rv;
                    else
                    r[rv]=ru;
                }
                if(cnt==n-1)
                {
                    cout<<res<<endl;
                    break;
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen(task".INP", "r", stdin);
    freopen(task".OUT", "w", stdout);
    ll test_case=1; //cin>>test_case;
    while(test_case--)
    {
        input(), lds_go_goooo();
        cout<<'\n';
    }
    return 0;
}
