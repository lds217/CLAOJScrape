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

ll dp[31][31][51];	
ll n,m,k;
void input()
{
	cin>>n>>m>>k;
}

ll sol(ll w,ll h, ll cnt)
{
	ll &res=dp[w][h][cnt];
	if(res!=-1)	return res;
	if(w*h<cnt)	return res=1e9;
	if(cnt==0||w*h==cnt) return res=0;
	res=1e9;
	FOR(i,0,cnt)
	{
		FOR(j,1,w-1)
			res=min(res,sol(j,h,i)+sol(w-j,h,cnt-i)+h*h);
		FOR(j,1,h-1)
			res=min(res,sol(w,j,i)+sol(w,h-j,cnt-i)+w*w);
	}
	return res;
	
}

void lds_go_goooo()
{
	cout<<sol(n,m,k);
}

int main()
{
 	ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen(task".INP", "r", stdin);
    //freopen(task".OUT", "w", stdout);
    	mset(dp,-1);
    ll test_case=1; cin>>test_case;
    while(test_case--)
    {
        input(), lds_go_goooo();
        cout<<'\n';
    }
    return 0;
}
