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
#include <bits/stdc++.h>
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
#define task "dream"

using namespace std;
typedef int64_t ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
const ll maxn=1e5+2;
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
vector <ii> v;
int n,k;
void input()
{

}
int a[maxn];
void lds_go_goooo()
{
    
    cin>>n>>k;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        v.push_back({a[i],i});
    }
    sort(ALL(v));
     int j=0;
    int x=v[0].second;
    int dem=0;
    while (j<=n-1)
    {
        while (v[j].first==v[j+1].first&&j<=n-2)
        {
            if (v[j+1].second-x<=k-1){
            j++;
            }
            else break;
        }
        dem++;
        j++;x=v[j].second;
    }
    cout<<dem;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("DREAM.INP","r",stdin);
    freopen("DREAM.OUT","w",stdout);
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
