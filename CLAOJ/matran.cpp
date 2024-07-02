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
const ll maxn=55;
const ll B=-1312321321;

ll n, m, f[maxn][maxn];
vector<ll>a;
queue<ll>q;
int dx[4]={0, 1, 0, -1};
int dy[4]={1, 0, -1, 0};

void input()
{
    mset(f, 0);
    cin>>n>>m;
    FOR(i, 1, n)
    {
        FOR(j, 1, m)
        {
            f[i][j]=B;
            ll x; cin>>x;
            a.pb(x);
        }
    }
}

void solve()
{
    sort(ALL(a));
    ll x=1, y=1;
    ll xoay=0;
    FOR(i, 0, m*n-1) q.push(a[i]);
    while(!q.empty())
    {
        ll u=q.front();
        q.pop();
        f[x][y]=u;
        ll X=x+dx[xoay], Y=y+dy[xoay];
        if (f[X][Y]!=B)
        {
            xoay=(xoay+1)%4;
            x+=dx[xoay];
            y+=dy[xoay];
        }
        else
        {
            x=X; y=Y;
        }
    }
    FOR(i, 1, n)
    {
        cout<<"\n";
        FOR(j, 1, m) cout<<f[i][j]<<" ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t=1;
    while(t--)
    {
        input();
        solve();
        cout<<"\n";
    }
}
// luoi vl the
