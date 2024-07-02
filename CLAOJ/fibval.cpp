#include <bits/stdc++.h>
#define FOR(i, a, b) for(ll i=a; i<=b; i++)
#define FORD(i, a, b) for(ll i=a; i>=b; i--)
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define mp make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))

using namespace std;
typedef int64_t ll;

ll l, r;
char v[10]={'.', 'C', 'D', 'E', 'F', 'G', 'A', 'B', 'C', 'D'};
vector<ll>f(46, 1);

void input()
{
    cin>>l>>r;
}

void fib ()
{
    FOR(i, 2, 45) f[i]=f[i-1]+f[i-2];
}

void solve()
{
    fib();
    FOR(i, l, r)
    {
        f[i]%7==0 ? cout<<v[7]<<' ':cout<<v[f[i]%7]<<' ';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t=1;
    while (t--)
    {
        input();
        solve();
        cout<<"\n";
    }
    return 0;
}
