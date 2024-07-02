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
#define task "ANTS"

using namespace std;
typedef int64_t ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
const ll maxn=2e4+2;
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
ll w,h,k,t;
vector <array<ll,3>> a;
vector <array<ll,3>> ax[150],ay[150];
void input()
{
    cin>>w>>h>>k>>t;
    FOR(i,1,k)
    {
        int x,y,d;
        cin>>x>>y>>d;
        if(d==1||d==3)
            ax[y].pb({x,(d==1?1:-1),i});
        else
            ay[x].pb({y,(d==2?1:-1),i});
    }
}

array<ll,3> ans[maxn];
void lds_go_goooo()
{
   FOR(i,0,w)
   {
    if(!ay[i].size())
        continue;
     vector<array<ll,3> > res;
        sort(ALL(ay[i]));
        for( auto [pos,d,id]:ay[i] )
        {
            ll cur=((pos*1LL+t*d)%(2*h)+(2*h))%(2*h);
            if(cur>h)   cur=2*h-cur,d*=-1;
           if(cur==h||!cur)    d=(cur==0?1:-1);
            res.pb({cur,d,id});
        }
        sort(ALL(res));
        int cnt=0;
        for(auto [pos,d,id]:res)
            ans[ay[i][cnt++][2]]={i,pos,(d==1?2:4)};
   } 
   FOR(i,0,h)
   {
    if(!ax[i].size())
        continue;
     vector<array<ll,3> > res;
        sort(ALL(ax[i]));
        for( auto [pos,d,id]:ax[i] )
        {
            ll cur=((pos*1LL+t*d)%(2*w)+(2*w))%(2*w);
            if(cur>w)   cur=2*w-cur,d*=-1;
            if(cur==w||!cur)    d=(cur==0?1:-1);
            res.pb({cur,d,id});
        }
        sort(ALL(res));
        int cnt=0;
        for(auto [pos,d,id]:res)
            ans[ax[i][cnt++][2]]={pos,i,(d==1?1:3)};
   } 
   FOR(i,1,k)
    cout<<ans[i][0]<<' '<<ans[i][1]<<' '<<ans[i][2]<<endl;
}

int main()
{
     //ios_base::sync_with_stdio(false);
    //cin.tie(0);
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
