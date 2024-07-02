#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e6 + 5;
int a, b, p;
int ans = 1;
int32_t main() {
    cin >> a >> b >> p;
    int x = min(a, b);

    if (x >= p) return cout << 0, 0;
    for(int i = 1; i <= x; i++) ans *= i, ans %= p;
    cout << ans;
    return 0;
}
