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
const ll maxn=2e3+10;
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


ll dp[2021][2021],n,g,k,a[maxn],cost[maxn][maxn];
#define int ll
void prepare()
{
	
	 if (k == 1) {
 		FOR(i,1,n)
 		{

 			FOR(j,i,n)
 			{
 				if(i==j)
 					cost[i][j]=0;
 				else
 					cost[i][j]=cost[i][j-1]+a[j]-a[max(0LL,(i+(j-1-i+1)/2)*1LL)];
 			}
 		}
	} 
	else
	{
		
		FOR(i,1,n)
		{
			ll s=0,c=0;
			FOR(j,i,n)
			{
				s+=a[j];
				int b=2*s;
				int l=j-i+1;
				c+=a[j]*a[j];
				if(b%(2*l)==0)
				{
					int x=b/(2*l);
					cost[i][j]=l*x*x-b*x+c;
				}
				else
				{
					int x1=b/(2*l);
					int x2=x1+1;
					cost[i][j]=min(l*x1*x1-b*x1+c,l*x2*x2-b*x2+c);
				}
			}
		}
	}
}


void input()
{
	cin>>n>>g>>k;
	FOR(i,1,n)	cin>>a[i];
}

void sol(int id,int l, int r,int optl,int optr)
{
	if(l>r)	return;
	int mid=(l+r)/2;
	ii best={inf,-1};
	for(int i=optl;i<=(min(mid,optr));i++)
		if(dp[id-1][i-1]+cost[i][mid]<best.fi)
		{
			best.fi=dp[id-1][i-1]+cost[i][mid];
			dp[id][mid]=best.fi;
			best.se=i;
		}	
	sol(id,l,mid-1,optl,best.se);
	sol(id,mid+1,r,best.se,optr);
}





void lds_go_goooo()
{
	prepare();
//	FOR(i,1,n)
//	{
//		FOR(j,1,n)
//			cout<<cost[i][j]<<' ';
//		cout<<endl;
//	}
	mset(dp,0x3f);
	dp[0][0]=0;
	
	FOR(i,1,g)
		sol(i,i,n,i,n);
	
	
	cout<<dp[g][n];
}

signed main()
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
