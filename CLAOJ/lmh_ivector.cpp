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
int x[maxn],t[maxn],ans[maxn],bit[MASK(18)+5];
void input()
{
	cin>>n;
	FOR(i,1,n)
		cin>>x[i];
	FOR(i,1,n)
		cin>>t[i];
		
}

int get(int x)
{
	int sum=0;
	while(x>0)
	{
		sum+=bit[x];
		x-=x&(-x);
	}
	return sum;
}

void update(int x,int val)
{
	while(x<=n)
	{
		bit[x]+=val;
		x+=x&(-x);
	}
}

ll find(ll val)
{
    ll j=0, sum=0;
    FORD(i, 18, 0)
    {
        if (j+MASK(i)<n && sum + bit[j+MASK(i)]<val)
        {
            sum+=bit[j+MASK(i)];
            j+=MASK(i);
        }
    }
    return j+1;
}

void lds_go_goooo()
{
//	update(6);
	FOR(i,1,n)
	{
		ans[x[i]]=get(n-x[i]);
		update(n-x[i]+1,1);
	}
	FOR(i,1,n)
		cout<<ans[i]<<" ";
	
	cout<<endl;
	mset(bit,0);
	FOR(i,1,n)	update(i,1);
	FOR(i,1,n)
	{
		ll pos=find(t[i]+1);
		ans[pos]=i;
		update(pos,-1);
	}
	FOR(i,1,n)	cout<<ans[i]<<' ';
		
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
