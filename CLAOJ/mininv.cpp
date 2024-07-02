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

ll n;
ll a[maxn];
void input()
{
	cin>>n;
	FOR(i,1,n)
		cin>>a[i],a[i]=abs(a[i]);
}

long long tree[4*maxn];

void update(int id, int l, int r, int pos, int val)
{
    if (pos < l || pos>r)
        return;
    if (l == r)
    {
        tree[id] += val;
        return;
    }
    int mid = (l + r) / 2;
    update(id * 2, l, mid, pos, val);
    update(id * 2 + 1, mid + 1, r, pos, val);
    tree[id] = tree[id * 2]+ tree[id * 2 + 1];
}

int get(int id, int l, int r, int u, int v)
{
    if(u>r || l>v)
        return 0;
    if(u<=l&&r<=v)
        return tree[id];
    int mid=(l+r)/2;
    long long sumL=get(2*id,l,mid,u,v);
    long long sumR=get(2*id+1,mid+1,r,u,v);
    return sumL+sumR;
}
pair< ll,ll> res[maxn];
void lds_go_goooo()
{
//	FOR(i,1,n)
//		cout<<a[i]<<' ';
//	cout<<endl;
	ll sum=0;
	mset(tree,0);
	FOR(i,1,n)
	{
		res[i].fi=get(1,1,1e5,1,a[i]-1);
		update(1,1,1e5,a[i],1);
	}

//	FOR(i,1,n)
//		cout<<res[i].fi<<' ';
//	cout<<endl;
	mset(tree,0);
	reverse(a+1,a+n+1);
//	FOR(i,1,n)
//		cout<<a[i]<<' ';
	FOR(i,1,n)
	{
		res[n-i+1].se=get(1,1,1e5,1,a[i]-1);
		update(1,1,1e5,a[i],1);
	}
	FOR(i,1,n)
		sum+=min(res[i].fi,res[i].se);
	cout<<sum;
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
