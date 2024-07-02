#include <bits/stdc++.h>
using namespace std;
#define long long ll
int n, x, a[1000005], l[1000005], r[1000005], ma = 0;
int main() {
    cin >> n >> x;
    vector<int> b(n + 1, 1e6 + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    l[1] = r[n] = 1;
    for(int i = 2; i <= n; i++)
        if(a[i - 1] < a[i]) l[i] = l[i - 1] + 1;
        else l[i] = 1;
    for(int i = n - 1; i >= 1; i--)
        if(a[i + 1] > a[i]) r[i] = r[i + 1] + 1;
        else r[i] = 1;
    /*if(x == 0) {
        for(int i = 1; i <= n; i++) {
            int p = lower_bound(b.begin() + 1, b.end(), a[i]) - b.begin();
            b[p] = a[i];
            //for(int i = 1; i <= n; i++) cout << b[i] << ' ';
            //cout << '\n';
        }
        cout << lower_bound(b.begin() + 1, b.end(), 1e6 + 1) - b.begin() - 1;
        return 0;
    }*/
    for(int i = 1; i <= n; i++)
        if(a[i] < a[i + x + 1]) ma = max(ma, l[i] + r[i + x + 1]);
    cout << ma;
	return 0;
}
