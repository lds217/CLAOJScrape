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
typedef int64_t ll;
typedef long double ld;
typedef pair<double, double> ii;
typedef pair<ll, ii> iii;
const ll maxn=2e6+2;
const ll mod=26051968;
const ll inf=1e18;

const int moveX[]={0,0,1,-1};
const int moveY[]={-1,1,0,0};

bool maximize(ll &A, ll B)
{
    return A<B ? A=B, true : false;
}

bool minimize(double &A, double B)
{
    return A>B ? A=B, true : false;
}

ll POW(ll a, ll b)
{
    if (b==0) return 1;
    ll tmp=POW(a, b/2);
    return b%2==0 ? (tmp*tmp)%mod : (tmp*tmp*a) % mod;
}

ll n,p,l;
ii a[maxn];
double dp[maxn];
ll trace[maxn];
void input()
{
    cin>>n>>p>>l;
    FOR(i,1,n)
        cin>>a[i].fi>>a[i].se;

}


void lds_go_goooo()
{
   // FOR(i,0,n)
   //     dp[i]=1e9;
   mset(trace,0);
    dp[0]=0;
   FOR(i,1,n)
   {
    dp[i]=1e9;
    double w=0;  
    double vt=1e9;
        FORD(j,i,1)
        {
            w+=a[j].fi;
            minimize(vt,a[j].se); 
            if(w>p) break;
            if(minimize(dp[i],l/vt+dp[j-1]))
                trace[i]=j;
        }
   }
   cout<<dp[n]<<endl;
   stack<int> s;
   int j=n;
  // FOR(i,1,n)   cout<<trace[i]<<' ';
    //cout<<endl;
  while(trace[j]!=0)
   {
     s.push(j);
     j=trace[j]-1;
   }
    while(!s.empty())
        {cout<<s.top()<<' ';s.pop();}
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
