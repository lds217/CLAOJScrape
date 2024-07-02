#include <bits/stdc++.h>

using namespace std;

long long l, r, d, k, tong = 0;

int main() {
    cin.tie(0)->sync_with_stdio(NULL);
    cin >> l >> r >> d >> k;
    for (long long i = l; i <= r; i += d) {
        tong += (long long)abs(k - i);
    }

    cout << tong;
}
