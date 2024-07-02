#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n;
    cin >> n;
    long long a[n + 1];
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    long long f[n + 1];
    f[n] = 0;
    int iMax = n;
    for(int i = n - 1; i >= 1; --i){
        if(a[i] <= a[iMax]){
            f[i] = a[iMax] - a[i] + f[i + 1];
        }
        else{
            f[i] = f[i + 1];
            iMax = i;
        }
    }
    long long q;
    cin >> q;
    while(q--){
        long long t;
        cin >> t;
        cout << f[t] << endl;
    }
    return 0;
}
