#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, t, k;
    cin >> n >> k >> t;

    long long res = ceil((-1 + sqrt(8 * n / k)) / 2.0);

    cout << t * res;
}
