#include <bits/stdc++.h>
#define FOR(i,k,n) for(int i = k; i <= n; i++)
#define int long long
using namespace std;

const int N = 5e5+1;
int n, a[2*N], ans = -1E18, sum, dp[2*N];

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); 
    //freopen("1.inp","r",stdin);
   // freopen("SHOES.OUT","w",stdout);
    cin >> n;
    FOR(i,1,2*n-1) cin >> a[i], sum += a[i];
    FOR(i,1,2*n-2) if (a[i] + a[i+1]) dp[i] = 0; else dp[i] = dp[i-2] + 1;
    FOR(i,1,2*n-1) ans = max(ans, dp[i]);
    cout << -sum << ' ' << count(a+1,a+2*n,sum) << '\n' << ans;
}
