#include <bits/stdc++.h>
using namespace std;
long long n,m;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("CLOCK.inp","r",stdin);
    freopen("CLOCK.out","w",stdout);
    cin >> n >> m;
    cout << 1LL*(n+m)%60;
    return 0;
}
