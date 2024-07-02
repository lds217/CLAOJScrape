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
const ll mod=1e9+7;
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
    return b%2==0 ? (tmp*tmp)%mod :( (tmp*tmp)%mod*a) % mod;
}

ll n,k;
string s;
ll dp[33][33][3][3];

void input()
{
    cin>>n>>k;
    while(n>0)
    {
        s+='0'+n%2;
        n/=2;
    }
    reverse(ALL(s));
}    
#define int ll
int dpdg(int pos=0,int cnt=0, bool ok=0,bool started=0)
{
    if(pos>=s.size())
    {
        if(cnt) return(cnt-1)/k+1;
        else    return 0;
    }
    ll &res=dp[pos][cnt][ok][started];

    if(res!=-1)  return res;

    res=0;
    int lim=(ok?1:s[pos]-'0');
    for(int i=0;i<=lim;i++)
        res+=dpdg(pos+1,cnt+(started==1&&i==0),(ok|(i<lim)),(i|started));

    return res;
}

void lds_go_goooo()
{
    mset(dp,-1);
   cout<<dpdg();
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen(task".INP", "r", stdin);
    //freopen(task".OUT", "w", stdout);
    ll test_case=1; 
    while(test_case--)
    {
        input(), lds_go_goooo();
        cout<<'\n';
    }
    return 0;
}
