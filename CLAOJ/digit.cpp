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

unsigned long long n;

unsigned long long findbin(unsigned long long n1,unsigned long long x,bool flip)
{
	if(x==1)
	{
	    if(flip==0)
    		if(n1==1)
    			return 1;
    		else
    			return 0;
    	else
    	    if(n1==1)
    			return 0;
    		else
    			return 1;
	}
	ll curr;
	unsigned long long mid=pow(2,x-1);
	if(n1>mid)
		curr=findbin(mid-(pow(2,x)-n1),x-1,1);
	else
		curr=findbin(n1,x-1,0);
		
	if(flip==1)
		if(curr==0)
			return 1;
		else
			return 0;
	else
		if(curr==0)
			return 0;
		else
			return 1;
}

void input()
{
	cin>>n;
	
}
void lds_go_goooo()
{
	long long x=ceil(log2(n));
	if(x==0)
		x=1;
	//cout<<x<<endl;
	cout<<findbin(n,x,0);
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
