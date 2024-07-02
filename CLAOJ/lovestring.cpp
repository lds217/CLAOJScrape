// Created by Sang lớp 9
// Какого черта ты переводишь?
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

int n, k, a[1005], cnt[1005];

int32_t main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
    #ifndef Sang
        freopen("main.inp", "r", stdin);
        freopen("main.out", "w", stdout);
    #endif
    int t; cin >> t;
    while (t--){
        cin >> n >> k;
        FOR (i, 1, n) cin >> a[i];
        memset(cnt, 0, sizeof cnt);
        FOR (i, 1, n){
            if (a[i] - (i-1)*k >= 0) cnt[a[i]-(i-1)*k]++;
        }
        int best = 0;
        FOR (i, 1, 1000) if (cnt[best] < cnt[i]) best = i;
        cout << n-cnt[best] << endl;
       
    }


    return 0;
}
