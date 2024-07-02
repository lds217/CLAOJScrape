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

template <class T>
bool minimize(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

template <class T>
bool maximize(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

ll POW(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll tmp = POW(a, b / 2);
    return b % 2 == 0 ? (tmp * tmp) % mod : ((tmp * tmp) % mod * a) % mod;
}

// End of template//
string s1, s2;
int dp[2000][2000];
int n, m;
void input()
{
    cin >> s1 >> s2;
    n = s1.size();
    m = s2.size();
     //reverse(ALL(s1));
     //reverse(ALL(s2));
      //cout << s1 << endl;
     //cout << s2 << endl;
}

void lds_go_goooo()
{
    s1 = " " + s1;
    s2 = " " + s2;
    FORD(i, n, 1)
        FORD(j, m, 1)
        {
            if (s1[i] == s2[j])
                dp[i][j] = dp[i + 1][j + 1] + 1;
            else
                dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
        }
    int k=dp[1][1];
    int i=0,j=0;
    deque<char> Q;
    while(k)
    {
        int tmpi=i,tmpj=j;
        FOR(x,tmpi+1,n)    
            FOR(y,tmpj+1,m)
                if((s1[x]==s2[y]&&dp[x][y]==k&&s1[x]>s1[i]) ||(s1[x]==s2[y]&&dp[x][y]==k&& dp[i][j]!=k))
                    i=x,j=y;
        Q.push_back(s1[i]);
        k--;
    }
    while(!Q.empty()&&Q.front()=='0')
        Q.pop_front();
    
    if(Q.empty())
    {
        cout<<0;
        return;
    }

    for(char i: Q)
         cout<<i;

    
    
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#define task "nummax"
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
