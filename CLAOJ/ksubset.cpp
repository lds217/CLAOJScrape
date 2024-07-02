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
#define task "ksubset"

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

int a[11],b[11];
int n,k;
void input()
{
	cin>>n>>k;
	FOR(i,1,n)
		cin>>a[i];
	FOR(i,1,k)
		cin>>b[i];
}
void solve()
{
    sort(a+1,a+1+n);
	do{
		int cnt=0,j=1;
		FOR(i,1,n)
		{
		//	cout<<a[i]<<' ';
			cnt+=a[i];
			if(cnt==b[j])
			{
				cnt=0;
				j++;
			}
			if(j==k+1&&i==n)
			{
				cout<<"YES";
				return;
			}
			if(j==k+1&&i!=n)
				break;
		}
		
	//	cout<<endl;
	}while(next_permutation(a+1,a+1+n));
	cout<<"NO";
}

int main()
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
