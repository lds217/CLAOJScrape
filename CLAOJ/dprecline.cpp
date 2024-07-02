#include <bits/stdc++.h>

using namespace std;

long long n, a[1000005], b[1000005], f[1000005][2];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 //   freopen(task".inp", "r", stdin);
  //  freopen(task".out", "w", stdout);
    memset(f,0,sizeof(f));
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i] >> b[i];
    f[1][0] = a[1];
    f[1][1] = b[1];
    for (int i = 2; i <= n; ++i) {
        f[i][0] = a[i] + max(f[i - 1][0] + abs(b[i] - b[i - 1]), f[i - 1][1] + abs(b[i] - a[i - 1]));
        f[i][1] = b[i] + max(f[i - 1][0] + abs(a[i] - b[i - 1]), f[i - 1][1] + abs(a[i] - a[i - 1]));
    }
    cout << max(f[n][0], f[n][1]);
    return 0;
}
