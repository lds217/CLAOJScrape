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
#define task "SUADUONG"
using namespace std;
typedef int64_t ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
const ll maxn = 3 * 1e2 + 2;
const ll mod = 26051968;
const ll inf = 1e18;

const int moveX[] = {0, 0, 1, -1};
const int moveY[] = {-1, 1, 0, 0};

bool maximize(ll &A, ll B)
{
    return A < B ? A = B, true : false;
}

bool minimize(ll &A, ll B)
{
    return A > B ? A = B, true : false;
}

ll POW(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll tmp = POW(a, b / 2);
    return b % 2 == 0 ? (tmp * tmp) % mod : (tmp * tmp * a) % mod;
}

// main
int n, m, sx, sy, d[maxn][maxn][maxn];
char a[maxn][maxn];
string s;

void input()
{
    cin >> n >> m;
    cin >> sx >> sy;
    FOR(i, 1, n)
        FOR(j, 1, m) cin>>a[i][j];
    cin >> s;
}

void lds_go_goooo()
{
    queue<tuple<int, int, int>> q;
    q.push({0, sx, sy});
    mset(d, -1);
    d[0][sx][sy] = 0;
    while (!q.empty())
    {
        auto [cnt, x, y] = q.front();
        q.pop();
        if (cnt == s.size())
        {
            cout << d[cnt][x][y];
            return;
        }
        if (a[x][y] == s[cnt])
            q.push({cnt + 1, x, y}),d[cnt+1][x][y]=d[cnt][x][y];
        FOR(i, 0, 3)
        {
            int nx = x + moveX[i];
            int ny = y + moveY[i];
            if (nx <= 0 || ny <= 0 || nx > n || ny > m)
                continue;
            if (d[cnt][nx][ny] == -1)
            {
                d[cnt][nx][ny] = d[cnt][x][y] + 1;
                q.push({cnt, nx, ny});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // freopen(task".INP", "r", stdin);
    // freopen(task".OUT", "w", stdout);
    ll test_case = 1;
 //   cin >> test_case;
    while (test_case--)
    {
        input(), lds_go_goooo();
        cout << '\n';
    }
    return 0;
}
