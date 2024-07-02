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
int n,m,a[maxn];
map <int,int> dup_neg,dup_pos;
map <int,int> neg,pos;

void input()
{
	cin>>n>>m;
	FOR(i,1,n)
	{
		cin>>a[i];
		if(a[i]>=0)
			pos[a[i]]++;
		else
			neg[a[i]]++;
	}
}

ll prop(ll n)
{
	return n*(n-1)/2;
}


void solve()
{
	ll res=0;
	FOR(i,1,n)
	{
		ll temp=m-a[i];
		if(temp==a[i])
		{
			if((a[i]>=0&&dup_pos[a[i]]==0)||(a[i]<0&&dup_neg[a[i]]==0))
			if(a[i]>=0)	res+=prop(pos[a[i]]),dup_pos[a[i]]=1;
			else res+=neg[a[i]],dup_neg[a[i]]=1;
		}
		else
		{
			if(temp<0&&a[i]<0)
				if(dup_neg[temp]==0&&dup_neg[a[i]]==0&&neg[temp]!=0&&neg[a[i]]!=0)
					res+=neg[temp]*neg[a[i]],dup_neg[temp]=dup_neg[a[i]]=1;
			if(temp>=0&&a[i]>=0)
				if(dup_pos[temp]==0&&dup_pos[a[i]]==0&&pos[temp]!=0&&pos[a[i]]!=0)
					res+=pos[temp]*pos[a[i]],dup_pos[temp]=dup_pos[a[i]]=1;
			if(temp<0&&a[i]>=0)
				if(dup_neg[temp]==0&&dup_pos[a[i]]==0&&neg[temp]!=0&&pos[a[i]]!=0)
					res+=neg[temp]*pos[a[i]],dup_neg[temp]=dup_pos[a[i]]=1;
			if(temp>=00&&a[i]<0)
				if(dup_pos[temp]==0&&dup_neg[a[i]]==0&&pos[temp]!=0&&neg[a[i]]!=0)
					res+=pos[temp]*neg[a[i]],dup_pos[temp]=dup_neg[a[i]]=1;
		}
	}
	cout<<res;
}	

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen(TASK".INP", "r", stdin);
    //freopen(TASK".OUT", "w", stdout);
    ll test_case=1; //cin>>test_case;
    while(test_case--)
    {
        input(), solve();
        cout<<'\n';
    }
    return 0;
}
