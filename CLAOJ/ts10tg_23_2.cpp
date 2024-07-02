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
#define task "ODDEVEN"

using namespace std;
typedef int64_t ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
const ll maxn=1e6+2;
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
//main
const long long k=1e9+7;
long long x,y,n;
ll a[1000005];
void input()
{
    cin>>x>>y>>n;
}

void lds_go_goooo()
{
    a[1]=x;
    a[2]=y;
    FOR(i,3,n)
        if(i%2)
            a[i]=abs(a[i-1]-a[i-2])%k;
        else    
            a[i]=(a[i-1]+a[i-2])%k;
    cout<<a[n];
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
