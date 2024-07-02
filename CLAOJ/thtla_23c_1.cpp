#include <bits/stdc++.h>

using namespace std;
#define reu(i, a, b) for(int i = a, _b = b; i <= _b; i++)
#define red(i, a, b) for(int i = a, _b = b; i >= _b; i--)
#define ii pair<int, int>
#define fi first
#define se second
#define M(i) (1LL << (i))
#define INF 1000000
typedef long long ll;
const int N = 1e8;

int n, d;
int a[N+5], ans = 0;

int calc(int n){
    if (n <= N) return a[n];
    if (n%2 == 0) return calc(n/2);
    else return calc(n/2) + calc(n/2 + 1);
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    a[0] = 0; a[1] = 1;
    reu(i, 1, N) if (i%2 == 1) a[i] = a[i/2] + a[i/2+1]; else a[i] = a[i/2];
    int n;
    cin >> n;
    red(i, n, n/2) ans = max(ans, calc(i));
    cout << ans;
    return 0;
}
