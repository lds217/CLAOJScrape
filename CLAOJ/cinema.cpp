#include <bits/stdc++.h>
#define FOR(i,k,n) for(int i = k; i <= n; i++)
#define FORR(i,k,n) for(int i = n; i >= k; i--)
#define pb push_back
#define all(x) begin(x),end(x)
#define pii pair<int,int>
#define fi first
#define se second
#define int long long
using namespace std;

const int N = 1e6+1;
int n, t, a[N], k[N], l, r, ans, mn[N], mx[N], mxx = -1e9+7, mnn = 1e9+7;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> t;
    k[0] = 0;
    FOR(i,1,n) cin >> a[i], k[i] = k[i-1] + a[i];
    FOR(i,0,n){
        mnn = min(mnn, k[i]);
        mn[i] = mnn;
    }
    FORR(i,0,n){
        mxx = max(mxx, k[i]);
        mx[i] = mxx;
    }
    while (t--){
        cin >> l >> r; 
        cout << mx[r] - mn[l-1] << '\n';
    }
}
