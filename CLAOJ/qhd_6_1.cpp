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

#define FOR(i, a, b) for (ll i = a, _b = b; i <= _b; i++)
#define FORD(i, a, b) for (ll i = a, _b = b; i >= _b; i--)
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define mp make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)

using namespace std;
typedef int64_t ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
const ll maxn = 2e5 + 100;
const ll mod = 998244353;
const ll inf = 1e18;

const int moveX[] = {0, 0, 1, -1};
const int moveY[] = {-1, 1, 0, 0};

template <class T> bool minimize(T &a, T b) { if (a > b) { a = b; return true; } return false;}

template <class T> bool maximize(T &a, T b) { if (a < b) { a = b; return true; } return false;}

ll POW(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll tmp = POW(a, b / 2);
    return b % 2 == 0 ? (tmp * tmp) % mod : ((tmp * tmp) % mod * a) % mod;
}

// End of template//
int dp[10006][101];
int t[10006][101];
int a[maxn];
int n,k;
void input()
{
    cin>>n>>k;
    FOR(i,1,n)
        cin>>a[i];
}
// dp 0 1 2
// 1  0 1 0
// 2  1 0 0
// 3  1 

void lds_go_goooo()
{
    if(n<=20)
    {
        FOR(mask,0,MASK(n)-1)
        {
            ll sum=a[1];
            FOR(j,1,n-1)
                if(BIT(mask,j))
                    sum+=a[j+1];
                else
                    sum-=a[j+1];
            
            if(sum%k==0 && sum>=0)
            {
                cout<<1<<endl;
                FOR(j,1,n-1)
                if(BIT(mask,j))
                cout<<"+";
                else
                    cout<<"-";
                return;
            }
        }
        cout<<0;
    }
    else
    {
        dp[1][(a[1]+10000*k)%k]=1;
        FOR(i,1,n-1)
            FOR(j,0,k-1)    if(dp[i][j])
            {
                dp[i+1][(j+a[i+1]+10000*k)%k]=dp[i][j];
                t[i+1][(j+a[i+1]+10000*k)%k]=1;
                dp[i+1][(j-a[i+1]+10000*k)%k]=dp[i][j];
                t[i+1][(j-a[i+1]+10000*k)%k]=-1;
            }
       /* FOR(i,1,n)
            FOR(j,0,k-1)
                cout<<dp[i][j]<<" \n"[j==k-1];*/
        if(dp[n][0])
        {
            vector <char> ans;
            int i=n,j=0;
            while(i>1)
            {
                if(t[i][j]==1)
                {
                    ans.pb('+');
                    j=(j-a[i]+10000*k)%k;
                    i--;
                }
                else
                {
                    ans.pb('-');
                    j=(j+a[i]+10000*k)%k;
                    i--;
                }
                
            }
            cout<<1<<endl;
            reverse(ALL(ans));
            for(char   k: ans)
                cout<<k;
        }
        else
            cout<<0;

    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #define task "kmult"
    freopen(task".INP", "r", stdin);
    freopen(task".OUT", "w", stdout);
    // int sub=1;
    // cin>>sub;
    ll test_case = 1; // cin>>test_case;
    while (test_case--)
    {
        input();
        lds_go_goooo();
        cout << '\n';
    }
    return 0;
}
