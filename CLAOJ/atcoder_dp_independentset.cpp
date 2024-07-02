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

struct lp{
    //white la co the to trang, black la co the to den
    long long black,white;
};

int n;
vector <ll> k[maxn];
void input()
{
    cin>>n;
    FOR(i,1,n-1)
    {
        int u,v;
        cin>>u>>v;
        k[u].push_back(v);
        k[v].push_back(u);
    }

}

void add(ll& a,ll b)
{
    a+=b;
    if(a>=mod)
        a-=mod;
}

ll mul(int a,int b)
{
    return (ll) a* b % mod;
}

lp dfs(int u,int par)
{
    int fullwhite=1;
    int hasblack=0;
    for(int i=0;i<k[u].size();i++)
    {
        int v=k[u][i];
        if(v!=par)
        {
            lp nextt=dfs(v,u);
            ll tmp=fullwhite;
            fullwhite=mul(nextt.white,fullwhite);
            hasblack=(mul(tmp,nextt.black)+mul(hasblack,nextt.black+nextt.white))%mod;
        }
    }
   lp tra;
    tra.black=fullwhite;
    tra.white=(fullwhite+hasblack)%mod;
    return tra;

}

void lds_go_goooo()
{
    lp ans=dfs(1,-1);
    cout<<(ans.white+ans.black)%mod<<endl;
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
