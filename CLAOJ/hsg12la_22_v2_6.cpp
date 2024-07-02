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
const ll maxn=5e5+100;
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
int n,m;
char a[202][202];
vector <ii> nhim,chau;
void input()
{
    cin>>n>>m;
    FOR(i,1,n)    
        FOR(j,1,m)  
        {
            cin>>a[i][j];
            if(a[i][j]=='X')
                nhim.pb({i,j});
            if(a[i][j]=='L')
                chau.pb({i,j});
        }
}

ll dist(int i,int j)
{
    return (chau[i].fi-nhim[j].fi)*(chau[i].fi-nhim[j].fi) + (chau[i].se-nhim[j].se)*(chau[i].se-nhim[j].se);
}
void lds_go_goooo()
{
    int ans=0;
    FOR(i,0,chau.size()-1)
    {
        if(a[chau[i].fi][chau[i].se]=='L'){
            int best=-1;
            FOR(j,0,nhim.size()-1)
                if(a[nhim[j].fi][nhim[j].se]=='X') 
                    if(best==-1||dist(i,best)>dist(i,j))
                        best=j;
            if(best==-1)
                continue;
            int cnt=0;
            FOR(z,0,nhim.size()-1)
                if(a[nhim[z].fi][nhim[z].se]=='X')
                    if(z!=best&&dist(i,best)==dist(i,z))
                    {
                        cnt++;
                        a[chau[i].fi][chau[i].se]=a[nhim[best].fi][nhim[best].se]=a[nhim[z].fi][nhim[z].se]='.';
                    }
            if(cnt)
                ans++;
        }
    }
    cout<<ans;

   /* FOR(i,1,n)
    {
        FOR(j,1,m)  cout<<a[i][j];
        cout<<endl;
    }*/
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
