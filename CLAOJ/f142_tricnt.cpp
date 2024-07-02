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
#define task "SUADUONG"

using namespace std;
typedef int64_t ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
const ll maxn=2*1e5+100;
const ll mod=1000000007;
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

ii a[maxn];
ll n;
ll pre[maxn];
ll ans=0;
void input()
{
    cin>>n;
    FOR(i,1,n)
    {
        cin>>a[i].se>>a[i].fi;
        pre[a[i].se]+=a[i].fi;
        if(a[i].fi>=3)
            ans=(ans+a[i].fi*(a[i].fi-1)*(a[i].fi-2)/6)%mod;
    }
}


void lds_go_goooo()
{
    FOR(i,1,200001)
        pre[i]+=pre[i-1];
    
   // FOR(i,1,5) cout<<pre[i]<<' ';
    sort(a+1,a+n+1,[&](ii a,ii b){
        return a.se<b.se;
    });
    FOR(i,1,n)
        if(a[i].fi>=2)
            ans=(ans+(pre[2*a[i].se-1]-a[i].fi)*a[i].fi*(a[i].fi-1)/2)%mod;
    
    FOR(i,1,n)
        FOR(j,i+1,n)
            ans=(ans+a[i].fi*a[j].fi*(pre[a[i].se+a[j].se-1]-pre[a[j].se])%mod)%mod;
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
