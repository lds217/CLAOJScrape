#include <bits/stdc++.h>
using namespace std;
#define Sang 1
#define int long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'
#define FOR(i, a, b) for(__typeof(b) i = a, _b = b; i <= _b; ++i)
#define FORD(i, a, b) for(__typeof(a) i = a, _b = b; i >= _b; --i)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define MASK(i) (1ll<<(i))
#define BIT(t, i) (((t)>>(i))&1)
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> pii;
const int MOD = 1e9+7;
const int N = 1e5+5;
const int INF = 0x3f3f3f3f;

template <class T> bool minimize(T &a, T b) { if (a > b) { a = b; return true; } return false;}

template <class T> bool maximize(T &a, T b) { if (a < b) { a = b; return true; } return false;}

//   ****   ****
//  *     *     *
//  *   VOI24   *
//    *       *
//       * *  

// SUB1

int n, k, dp[255][255], a[255];
int L, R;
multiset<int> ms;
set<int> sets;

int cost(int l, int r){
    while (L > l){
        ms.insert(a[--L]);
        sets.insert(a[L]);
    }
    while (L < l){
        if (ms.count(a[L]) == 1) sets.erase(a[L]);
        ms.erase(ms.find(a[L++]));
    }
    while (R > r){
        if (ms.count(a[R]) == 1) sets.erase(a[R]);
        ms.erase(ms.find(a[R--]));
    }
    while (R < r) {
        ms.insert(a[++R]);
        sets.insert(a[R]);
    }
    return sets.size();
}

int32_t main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
    #ifndef Sang
        freopen("main.inp", "r", stdin);
        freopen("main.out", "w", stdout);
    #endif
    cin >> n >> k;
    FOR (i, 1, n) cin >> a[i];
    int ans = 0;
    L = 1; R = 1;
    ms.insert(a[1]);
    sets.insert(a[1]);
    FOR (j, 1, k){
        FOR(i, j, n){
            FORD(l, i-1, 0){
                // cout << l+1 << ' ' << i << ' ' << cost(l+1, i) << endl;
                maximize(dp[i][j], dp[l][j-1] + cost(l+1, i));
            }
        }
        maximize(ans, dp[n][j]);
    }
    cout << ans;

    return 0;
}
