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

int a[1001][1001],prefix[1001][1001];
int n,m,x,y;
int minn=1e9;
int maxx=-1e9;


void input()
{
	cin>>n>>m>>x>>y;
    FOR(i,1,n)
        FOR(j,1,m)
        {
            cin>>a[i][j];
           minn=min(minn,a[i][j]); 
           maxx=max(maxx,a[i][j]);
        }
}

bool findmed(int med)
{
	vector<vector<int> > prefix(n+5, vector<int>(m+5, 0));
    FOR(i,1,n)
        FOR(j,1,m)
        {
           	prefix[i][j]=prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1];
            if(a[i][j]<=med)
                prefix[i][j]++;
        }
 //   cout<<med<<endl;
   /* FOR(i,1,n)
    {
        FOR(j,1,m)
        	cout<<prefix[i][j]<<' ';
        cout<<endl;
	}*/
//	cout<<endl;
	int k=(x*y+1)/2;
    FOR(i,x,n)
    {
        FOR(j,y,m)
        {
        	if(prefix[i][j]+prefix[i-x][j-y]-prefix[i-x][j]-prefix[i][j-y]<k)
        		return 1;
    	}
    	//cout<<endl;
    }
   // cout<<endl;
    return 0;
}


void solve()
{
	int l=minn,r=maxx;
	findmed(3);
	while(r>=l)
	{
		
		int mid=(l+r)/2;
		if(findmed(mid))
			l=mid+1;
		else
			r=mid-1;
	}
	cout<<l;
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
        input(), solve();
        cout<<'\n';
    }
    return 0;
}
