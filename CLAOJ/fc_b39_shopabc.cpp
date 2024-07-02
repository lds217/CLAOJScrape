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
const ll maxn=2*1e5+2;
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
int n;
char a[maxn];
void input()
{
    cin>>n;
    FOR(i,1,n)  cin>>a[i];

}

long long pre[maxn];
long long f[maxn];

long long search(int l,int r, int val)
{
    while(l<r)
    {
        int mid=(l+r)/2;
        if(val-f[mid]>0)
            r=mid;
        else
            l=mid+1;
    }
    return l;
}

long long lds_go_goooo(char x)
{
    mset(pre,0);
    mset(f,0);
    FOR(i,1,n)
    {
        if(a[i]==x)
            pre[i]=pre[i-1]+1;
        else
            pre[i]=pre[i-1]-1;
        f[i]=min(f[i-1],pre[i]);
    }
	
	/*FOR(i,1,n)
	    cout<<f[i]<<' ';
	cout<<endl;
	FOR(i,1,n)
	    cout<<pre[i]<<' ';
	cout<<endl;*/
    long long ans=0;
    FOR(i,1,n)
    {
        long long l=search(0,i,pre[i]);
        if(pre[i]-pre[l]>0)
        ans=max(ans,i-l);
    }
    return ans;
        
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
        input(), cout<<max({lds_go_goooo('b'),lds_go_goooo('c'),lds_go_goooo('a')});
        cout<<'\n';
    }
    return 0;
}
