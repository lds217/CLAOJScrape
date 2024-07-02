// Template //
#include <bits/stdc++.h>
#define FOR(i, a, b) for(ll i=a, _b=b; i<=_b; i++)
#define FORD(i, a, b) for(ll i=a, _b=b; i>=_b; i--)
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define mp make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
#define MASK(i) (1LL<<(i))
#define BIT(x, i) (((x)>>(i))&1)
#define task "PROTEST"
#define int long long

using namespace std;
typedef int64_t ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
const ll maxn=1e+5;
const ll mod=1e9+9;
const ll inf=1e18;


bool maximize(ll &A, ll B)
{
    return A<B ? A=B, true : false;
}

bool minimize(ll &A, ll B)
{
    return A>B ? A=B, true : false;
}

ll POW(ll a, ll b)
{
    if (b==0) return 1;
    ll tmp=POW(a, b/2);
    return b%2==0 ? (tmp*tmp)%mod : (tmp*tmp*a) % mod;
}
        // Main Function //

long long cow[maxn],prefix[maxn],f[maxn],n=1,tree[maxn*4];
pair<int,int> prefixpair[maxn];

void update(int id, int l, int r, int pos, int val)
{
    if (pos < l || pos>r)
        return;
    if (l == r)
    {
        tree[id] += val;
        return;
    }
    int mid = (l + r) / 2;
    update(id * 2, l, mid, pos, val);
    update(id * 2 + 1, mid + 1, r, pos, val);
    tree[id] = tree[id * 2]+ tree[id * 2 + 1];
}

int get(int id, int l, int r, int u, int v)
{
    if(u>r || l>v)
        return 0;
    if(u<=l&&r<=v)
        return tree[id];
    int mid=(l+r)/2;
    long long sumL=get(2*id,l,mid,u,v);
    long long sumR=get(2*id+1,mid+1,r,u,v);
    return sumL+sumR;
}

void input()
{
    cin>>n;
    FOR(i,1,n)
        cin>>cow[i];
}

void nen()
{
    sort(prefixpair,prefixpair+n+1);
    prefix[prefixpair[0].second] = 1;
    int cnt=1;
    FOR(i,1,n)
        if(prefixpair[i].first!=prefixpair[i-1].first)
            prefix[prefixpair[i].second]=++cnt;
        else
            prefix[prefixpair[i].second]=cnt;
}

void solve()
{
    FOR(i,1,n){
        prefixpair[i].first= prefixpair[i-1].first+cow[i];
        prefixpair[i].second=i;
    }
    nen();
    //FOR(i,0,n)  cout<<prefix[i]<<' ';
    update(1,1,n,prefix[0],1);
    FOR(i,1,n)
    {
        f[i]=get(1,1,n,1,prefix[i])%mod;
        update(1,1,n,prefix[i],f[i]);

    }
    cout<<f[n];
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen(task".INP", "r", stdin);
    freopen(task".OUT", "w", stdout);
    ll test_case=1; //cin>>test_case;
    while(test_case--)
    {
        input(), solve();
        cout<<'\n';
    }
    return 0;
}
