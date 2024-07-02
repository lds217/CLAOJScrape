#include <utility>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <unordered_map>
#include <map>
#include <iomanip>
#include <vector>
#include <iostream>
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
#define task "SUADUONG"

using namespace std;
typedef int64_t ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
const ll maxn=1e5+2;
const ll mod=1e9+7;
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


unsigned int countSetBits(unsigned int n)
{
    unsigned int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int n;bool love[22][22];

void input()
{
    cin>>n;
    FOR(i,1,n)
        FOR(j,1,n)
            cin>>love[i][j];

}

void add(ll& a,ll b)
{
    a+=b;
    if(a>=mod)
        a-=mod;
}

ll dp[2097153];
void lds_go_goooo()
{
    dp[0]=1;
    FOR(mask,0,(1<<n)-2)
    {
         int a=countSetBits(mask);
        FOR(b,0,n-1)
            if(love[a+1][b+1]&& (mask&(1<<b))==0)
                add(dp[mask ^(1<<b)],dp[mask]);
    }
    cout<<dp[(1<<n)-1];
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
        cout<<endl;
    }
    return 0;
}

/*


 d8b d8b
888888888
`Y88888P'       "Heart"
 `Y888P'      Le Thanh Dat
  `Y8P'
   `Y'
   
*/
