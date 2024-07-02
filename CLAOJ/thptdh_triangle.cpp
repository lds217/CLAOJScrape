#include <bits/stdc++.h>

using namespace std;

signed main() {
    long long n, x = 1;

    cin >> n;

    for (long long i = 1; i <= n; i++) {
        for (long long j = 1; j <= (n - x); j++) {
            cout << " ";
        }
        for (long long j = n - x + 1; j <= n; j++) {
            cout << j;
        }
        for (long long j = n - 1; j >= n - x + 1; j--) {
            cout << j;
        }
        x++;
        cout << endl;
    }
}
