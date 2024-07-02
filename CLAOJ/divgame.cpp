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

int minprime[10000005];
long long n;
void prepare()
{
	mset(minprime,0);
	for(int i=2;i*i<=1e7;i++)
		if(minprime[i]==0)
			for(int j=i*i;j<=1e7;j+=i)
				if(minprime[j]==0)
					minprime[j]=i;
	for(int i=2;i<=1e7;i++)
			if(minprime[i]==0)
				minprime[i]=i;
}

void input()
{
	cin>>n;
}
void lds_go_goooo()
{
	unordered_map <long long,bool> k;
	int cnt=0;
	if(n<=1e7)
	{
		while(n!=1)
		{
			if(k[minprime[n]]==0)
			{
				k[minprime[n]]=1;
				cnt++;
			}
			n/=minprime[n];
		}
	}
	else
	{
		for(long long i=2;i*i<=n;i++)
		{
			if(n%i==0)
			{
				cnt++;
    			while(n%i==0)
    				n/=i;
			}
		}
		if(n!=1)
		    cnt++;
	}
	cout<<cnt;
}

int main()
{
 	ios_base::sync_with_stdio(false);
    cin.tie(0);
    prepare();
    //freopen(task".INP", "r", stdin);
    //freopen(task".OUT", "w", stdout);
    ll test_case=1; cin>>test_case;
    while(test_case--)
    {
        input(), lds_go_goooo();
        cout<<'\n';
    }
    return 0;
}
