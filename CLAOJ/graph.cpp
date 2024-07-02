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
typedef pair<int, int> ii;
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

ii nodes[4*maxn];


void down(int id){ // down but it's on the top!!!
    int &t = nodes[id].se;
    nodes[id << 1].fi += t;
    nodes[(id << 1) + 1].fi += t;
    nodes[id << 1].se += t;
    nodes[(id << 1) + 1].se += t;
    t = 0;
}

void update(int id, int l, int r, int u, int v){
    if (l > v || u > r) return;
    if (l >= u && v >= r){
        nodes[id].fi+=-1;
        nodes[id].se+=-1;
        return;
    }
    down(id);
    int mid = (l + r) >> 1;
    update(id << 1, l, mid, u, v);
    update((id << 1)+1, mid+1, r, u, v);
}
int cur;
void find(int id,int l,int r, int pos)
{
	if (l > pos || r < pos) return ;
	if (l ==pos&&r==pos)
	{
		cur=nodes[id].fi;return;
	}
	down(id);	
	int mid = (l + r) >> 1;
    find(id << 1, l, mid, pos);
    find((id << 1)+1, mid+1, r, pos);
    return;

}
ll a[maxn],pre[maxn];
	ll n;
void input()
{
	mset(a,0);
	mset(pre,0);

	cin>>n;
	
}

void lds_go_goooo()
{
	
	
	ll odd=0,sum=0;
	FOR(i,1,n)
	{
		cin>>a[i];
		if(a[i]%2)
			odd++;
		sum+=a[i];
	}
	if(odd%2)
	{
		cout<<"NO";
		return;
	}
	if(sum%2)
	{
		cout<<"NO";
		return;
	}
	sort(a+1,a+n+1,greater<int>());
	FOR(i,1,n)
		pre[i]+=pre[i-1]+a[i];
	
	FOR(i,1,n)
	{
		ll s=0;
		FOR(j,i+1,n)
			s+=min(a[j],i);
		if(pre[i]>i*(i-1)+s)
		{
			cout<<"NO";
			return;
		}
		
	}
	cout<<"YES";
}

int main()
{
 	ios_base::sync_with_stdio(false);
    cin.tie(0);
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
