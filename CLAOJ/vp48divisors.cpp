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



//main

int n,q;
short tree[49603*2+2][1230];
int prime[10001],compress_prime[10001];

	int cnt=0;

void sieve()
{
//	mset(prime,0);mset(compress_prime,0);
	for(int i=2;i*i<=10000;i++)
		if(!prime[i])
			for(int j=i << 1;j<=10000;j+=i)
				if(!prime[j])
					prime[j]=i;
					
	FOR(i,2,10000)	if(!prime[i])	prime[i]=i;
	FOR(i,2,10000)	if(prime[i]==i) compress_prime[i]=++cnt;
}

void build()
{
	FORD(i,n-1,0)
		FOR(j,1,1229)
			tree[i][j]=tree[i<<1][j]+tree[i<<1|1][j];
}



vector <int> pre(int x)
{
	vector <int> a(1231);
	while(x>1)
	{
		a[compress_prime[prime[x]]]++;
		x/=prime[x];
	}
	return a;
}

void update(int pos,int val)
{
	vector <int> a=pre(val);
	pos+=n;
	FOR(i,1,1229)	tree[pos][i]=a[i];
	for(;pos>0;pos>>=1)
		FOR(i,1,1229)
			tree[pos>>1][i]=tree[pos][i]+tree[pos^1][i];
}

vector <int> get(int l,int r)
{
	vector <int> res(1231);
	for(l+=n,r+=n;l<r;l>>=1,r>>=1)
	{
		if(l&1)
		{
			FOR(i,1,1229)	res[i]+=tree[l][i];
			l++;
		}
		if(r&1)
		{
			r--;
			FOR(i,1,1229)	res[i]+=tree[r][i];
		}
	}
	return res;
}

void input()
{
	sieve();
	cin>>n;
	FOR(i,n,2*n-1)
	{
		int tmp;
		cin>>tmp;
		vector <int> res=pre(tmp);
		FOR(j,1,1229)
			tree[i][j]=res[j];
	}
	//debug
/*	cout<<compress_prime[5];
	cout<<tree[n+1][1]<<' '<<tree[n+1][2]<<' '<<tree[n+1][3]<<endl;
	cout<<tree[n+2][1]<<' '<<tree[n+2][2]<<' '<<tree[n+2][3]<<endl;
	cout<<tree[n+3][1]<<' '<<tree[n+3][2]<<' '<<tree[n+3][3]<<endl;*/
}
void lds_go_goooo()
{
	build();
	cin>>q;
	while(q--)
	{
		bool type;
		cin>>type;
		if(type==0)
		{
			int pos,val;
			cin>>pos>>val;
			update(pos-1,val);
		}
		else
		{
			int l,r;
			cin>>l>>r;l--;
			vector <int> ans=get(l,r);
			long long fil=1;
			FOR(i,1,1229)
				if(ans[i])	(fil*=(ans[i]+1))%=(1000000007);
			cout<<fil<<endl;
		}
	}
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
