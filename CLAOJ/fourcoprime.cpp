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

ll n;
ll dp[maxn],maxx=0;
void input()
{
    maxx=0;
    mset(dp,0);
  //  cin>>n;
    FOR(i,1,n)
    {
        int tmp;
        cin>>tmp;
        dp[tmp]++;
        maximize(maxx,tmp);
    }
}    
ll gt[maxn],igt[maxn];
void prepare(int lim)
{
	gt[0]=1;
	FOR(i,1,lim)
		gt[i]=(gt[i-1]*i)%mod;
	igt[lim]=POW(gt[lim],mod-2);
	FORD(i,lim,1)
		igt[i-1]=(igt[i]*i)%mod;
}

int C(int N, int k)
{
    if (k>N) return 0;
    return (((1LL*gt[N]*igt[k])%mod)*1LL*igt[N-k])%mod;
}

void lds_go_goooo()
{
   FOR(i,1,maxx)
   {
    for(long long j=2;j*i<=maxx;j++)
        dp[i]+=dp[i*j];
    dp[i]=C(dp[i],4);
   }

    FORD(i,maxx,1)
        for(long long j=2;j*i<=maxx;j++)
            dp[i]=(dp[i] - dp[i*j]+mod)%mod;
    cout<<dp[1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen(task".INP", "r", stdin);
    //freopen(task".OUT", "w", stdout);
    prepare(1000001);
    ll test_case=1; 
    while(cin>>n)
    {
        input(), lds_go_goooo();
        cout<<'\n';
    }
    return 0;
}
