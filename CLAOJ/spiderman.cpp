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
const ll maxn=2*1e4+2;
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

ll n,dp[105][2010],d[2013];
bool trace[111][2013];
void input()
{
	cin>>n;
	FOR(i,1,n)
		cin>>d[i];
}
void lds_go_goooo()
{
	mset(dp,0x3f);
	mset(trace,0);
	dp[1][0]=0;
	FOR(i,1,n)
		FOR(j,0,2000)
		{
			if(d[i]+j<=2000&&	minimize(dp[i+1][j+d[i]],max(dp[i][j],j+d[i])))	trace[i+1][j+d[i]]=1;
			if(j-d[i]>=0   &&	minimize(dp[i+1][j-d[i]],dp[i][j]))				trace[i+1][j-d[i]]=0;
		}

	/*FOR(i,1,n+1)
    {
        FOR(j,0,6)
            if(dp[i][j]<1e9)    cout<<dp[i][j]<<' ';
            else    cout<<-1<<' ';
        cout<<endl;
    }*/
    string ans="";
    int j=0;
    if(dp[n+1][0]<1e9)
    {
        FORD(i,n+1,2)
            if(trace[i][j]) j=j-d[i-1],ans+='U';
            else    j=j+d[i-1],ans+='D';
      //  cout<<ans;
        reverse(ALL(ans));
        cout<<ans;
        
    }
    else
        cout<<"IMPOSSIBLE";
			
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
