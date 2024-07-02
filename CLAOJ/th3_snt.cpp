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
#define task "SNT"

using namespace std;
typedef int64_t ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
const ll maxn=3*1e4+2;
const ll mod=1e9+7;
const ll inf=1e18;

const int moveX[]={0,0,1,-1};
const int moveY[]={-1,1,0,0};

bool maximize(ll &A, ll B)
{
    return A<B ? A=B, true : false;
}

bool minimize(ll &A, ll B)
{
    return A>B ? A=B, true : false;
}

int POW(ll a, ll b)
{
    if (b==0) return 1;
    ll tmp=POW(a, b/2);
    return b%2==0 ? (tmp*tmp)%mod : ((tmp*tmp) % mod*a) % mod;
}

//main
long long eratos[1000000];

void prepare()
{
    eratos[1]=1;
    for(int i=2;i*i<=1e6+5;i++)
        if(eratos[i]==0)
            for(int j=i*i;j<=1e6+5;j+=i)
                eratos[j]=1;
}

long long a[1000005];
long long n;

void input()
{
    cin>>n;
    FOR(i,1,n)  cin>>a[i];
}

bool dk(long long k)
{
    long long j=sqrt(k);
    return (j*j==k);
}
void solve()
{
    prepare();
    //cout<< eratos[1];
    FOR(i,1,n)
    {
        if(dk(a[i]))
            if(eratos[(int)sqrt(a[i])]==0)
                cout<<"YES";
            else
                cout<<"NO";
        else
            cout<<"NO";
        cout<<endl;
    } 
        
}

int main()
{
 	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
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
