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
#define task ""

using namespace std;
typedef int64_t ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
const ll maxn=1e5+2;
const ll mod=26051968;
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

struct hotel{
    int a,b,c;
};
hotel ks[maxn];
ll n;
ll f[maxn];

void input()
{
    cin>>n;
    FOR(i,1,n)
        cin>>ks[i].a>>ks[i].b>>ks[i].c;
}

bool dk(hotel A, hotel B)
{
    if(A.a==B.a)
            return A.b<B.b;
    return A.a<B.a;

}

void solve()
{
    sort(ks+1,ks+n+1,dk);
   // FOR(i,1,n) cout<<ks[i].a<<" "<<ks[i].b<<" "<<ks[i].c<<endl;
    FOR(i,1,n)
    {
        maximize(f[i],ks[i].c);
        FOR(j,i+1,n)
            if(i!=j&&ks[i].b<=ks[j].a)
            {
                maximize(f[j],f[i]+ks[j].c);
            }
    }
    //FOR(i,1,n)cout<<f[i]<<" ";
    cout<<*max_element(f+1,f+1+n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen(task".INP", "r", stdin);
    //freopen(task".OUT", "w", stdout);
    ll test_case=1; //cin>>test_case;
    while(test_case--)
    {
        input(), solve();
        cout<<'\n';
    }
    return 0;
}
