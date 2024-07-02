#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
const long long MOD = 1e9+7;
const long long N = 1e6+9;
ll a[N], n, T,x, ans, b[N];

void solve(){
    cin>>n; ans = LLONG_MIN;
    for(int i = 1; i <= n; i++)
        cin>>a[i];
    sort(a+1, a+1+n);
    for(int i = 1; i <= n; i++)
        cin>>b[i];
    sort(b+1, b+1+n);
    for(int i = 1; i <= n; i++)
        ans = max(abs(b[i] - a[i]), ans);
    cout<<ans<<'\n';    
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>T;
    while(T--)
        solve();
}
