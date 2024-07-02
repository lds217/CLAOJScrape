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

// Template //
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
#define task "ROAD"

using namespace std;
typedef int64_t ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
const ll maxn=1e2+2;
const ll mod=26051968;
const ll inf=1e18;


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
        // Main Function //
long long n;
long long a[25001];
long long dp[25001];


void input()
{
    cin>>n;
    FOR(i,1,n)  cin>>a[i];
}


void solve()
{
    mset(dp,0);
    if(n>=1)
        dp[1]=a[1];
    if(n>=2)
        dp[2]=a[1]+a[2];
    if(n>=3)
    {
        dp[3]=max(dp[2],max(a[1]+a[3],a[2]+a[3]));
        if(dp[2]>a[1]+a[3]&&dp[2]>a[2]+a[3])
        {
            dp[3]=dp[2];
        }
        else
        if(a[1]+a[3]>dp[2]&&a[1]+a[3]>a[2]+a[3])
        {
            dp[3]=a[1]+a[3];
        }
        else
        if(a[2]+a[3]>dp[2]&&a[2]+a[3]>a[1]+a[3])
        {
            dp[3]=a[2]+a[3];
        }
      
    }
    FOR(i,4,n)
        dp[i]=max(dp[i-1],max(a[i]+dp[i-2],a[i]+a[i-1]+dp[i-3]));
    cout<<dp[n]<<endl;
    ll i=n;
    stack <ll> ans;
    while(i>=1)
    {
        if(dp[i]==dp[i-1])
            i--;
        else
            if(dp[i]==dp[i-2]+a[i])
                ans.push(i),i-=2;
            else
                if(dp[i]==dp[i-3]+a[i]+a[i-1])
                    ans.push(i),ans.push(i-1),i-=3;
    }
    ll cnt=0;
    while(!ans.empty())
    {
        cnt++;
        cout<<ans.top()<<' ';
        if(cnt==10)
        {
            cnt=0;
            cout<<endl;
        }
        ans.pop();
    }
    
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
        //cout<<"SIU";
        input(), solve();
        cout<<'\n';
    }
    return 0;
}
