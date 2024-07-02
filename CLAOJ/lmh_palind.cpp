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

string s;
int a[maxn];
int n;
int cnt9=0;

void input()
{
	cin>>s;
	n=s.size();
	
	FOR(i,0,n-1)
	{
		a[i]=s[i]-'0';
		if(a[i]==9)
			cnt9++;
	}
}
void lds_go_goooo()
{
	if(cnt9==n)
	{
		FOR(i,0,n-1)
		cout<<a[i];
		return;
	}
	
	int mid=n/2;
	bool ck=0;
	int i=mid-1;
	int j= (n%2)?mid+1:mid;
	while(i>=0&&a[i]==a[j])
		i--,j++;
	if(i<0||a[i]<a[j])
		ck=1;
	while(i>=0)
	{
		a[j]=a[i];
		i--;
		j++;
	}
	if(ck==1)
	{
		int carry=1;
		i=mid-1;
		if(n%2==1)
		{
			a[mid]+=carry;
			carry=a[mid]/10;
			a[mid]%=10;
			j=mid+1;
		}
		else
			j=mid;
		while (i >= 0)
			{
				a[i] += carry;
				carry = a[i] / 10;
				a[i] %= 10;
	
				a[j++] = a[i--];
			}
	}
	FOR(i,0,n-1)
		cout<<a[i];
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
