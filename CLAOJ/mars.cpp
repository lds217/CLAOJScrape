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
#define task "SUADUONG"

using namespace std;
typedef int64_t ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
const ll maxn=2*1e4+2;
const ll mod=26051968;
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

ll POW(ll a, ll b)
{
    if (b==0) return 1;
    ll tmp=POW(a, b/2);
    return b%2==0 ? (tmp*tmp)%mod : (tmp*tmp*a) % mod;
}

//main

long long n,a,b,w,h;

void input()
{
	cin>>n>>a>>b>>w>>h;
}

bool check(ll mid)
{
    ll N=h/(a+mid*2), M=w/(b+mid*2);
    if (N*M>=n) return true;
    ll k=w/(a+mid*2), l=h/(b+mid*2);
    if (k*l>=n) return true;
    return false;
}

long long binsearch(long long l, long long r)
{
     if(check(r))    return r;
    if(l==r-1)  return l;
   
    long long mid=(l+r+1)/2;
    if(check(mid))
        return binsearch(mid,r);
    else    
        return binsearch(l,mid);
}

void lds_go_goooo()
{
	cout<<binsearch(0,min(w,h));
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
        input(), lds_go_goooo();
        cout<<'\n';
    }
    return 0;
}
