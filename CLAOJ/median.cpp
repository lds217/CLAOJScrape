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

long long n,k,pre[maxn];
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
long long tinhtien=0;
void input()
{
	mset(pre,0);
	cin>>n>>k;
	FOR(i,1,n)
	{
		int u;
		cin>>u;
		if(u>=k)
			pre[i]=pre[i-1]+1;
		else
			pre[i]=pre[i-1]-1;
		tinhtien=min(tinhtien,pre[i]);
	}
}
void lds_go_goooo()
{
	long long ans=0;
	FOR(i,0,n) pre[i]+=abs(tinhtien)+1;
	update(1,1,n,pre[0],1);
	FOR(i,1,n)
	{
		ans+=get(1,1,n,1,pre[i]);
		update(1,1,n,pre[i],1);
	}
	cout<<ans;
		
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
