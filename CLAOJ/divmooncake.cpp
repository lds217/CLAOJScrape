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
const ll maxn=3*1e6+2;
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

int n,k;
ll a[maxn];
void input()
{
    cin>>n>>k;
    k;
    FOR(i,1,n)cin>>a[i],a[i]+=a[i-1];
}

ll dp[maxn];

void lds_go_goooo()
{
   mset(dp,0);
    int s=0;
    dp[0]=0;
    deque<int> qmn;
    FOR(i,1,n)
    {

       if(i<k)
       {
               while(!qmn.empty()&&(a[i-1]-dp[i-2])<(a[qmn.back()-1]-dp[qmn.back()-2]))
                qmn.pop_back();
            qmn.push_back(i);
            dp[i]=a[i]-a[0];
            continue;
       }
        //FORD(j,i,i-k+1)
        while(!qmn.empty()&&(a[i-1]-dp[i-2])<(a[qmn.back()-1]-dp[qmn.back()-2]))
            qmn.pop_back();
        qmn.push_back(i);    
        if(qmn.front()<i-k+1)
            qmn.pop_front();
        dp[i]=max({dp[i],dp[i-1],a[i]-(a[qmn.front()-1]-dp[qmn.front()-2])});  
        
    }
    cout<<dp[n];
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
