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
#define task "ROAD"

using namespace std;
typedef int64_t ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
const ll maxn=1e2+2;
const ll mod=26051968;
const ll inf=1e18;


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
        // Main Function //

struct st{
    int x,y,z;
}   tp[10000],res[10000];
int remain=0,sum=0,tmp=0,mx=0,ans=1e9,n,a,b,c,d[10000];

void input()
{
    cin>>n>>a>>b>>c;
    FOR(i,1,n)  cin>>d[i],mx=max(mx,d[i]),sum+=d[i];
}



void solve()
{
    FORD(i,sum,mx)
    {
        FOR(j,1,n)
            tp[j]={0,0,0};
        tp[1].x=i;
        remain =0;
        tmp=i;
        
        FOR(j,1,n)
        {
            if(j>=2)
                remain+=d[j-2];
            
            if(tmp>=d[j])
                tmp-=d[j];
            else
            {
                tmp+=remain;
                tp[j-2].z=remain;
                if(d[j]<=tmp)
                {
                	if(d[j]+remain-tmp>=0)
                    	tp[j-2].z=remain-tmp+d[j];
                    remain=tmp-d[j];
                }
                else
                {
                    remain=0;
                    tp[j-1].y=d[j]-tmp;
                    remain-=(d[j]-tmp);
                }
                tmp=0;
                
            }
            int cost=0;
       		
        }
        int cost=0;
        FOR(j,1,n)
       		cost+=tp[j].x*a+tp[j].y*b+tp[j].z*c;
       	if(cost<ans)
       	{
       		ans=cost;
       		FOR(j,1,n)	res[j]=tp[j];
		}
        
    }
    cout<<ans<<endl;
    FOR(i,1,n)
        cout<<res[i].x<<' '<<res[i].y<<' '<<res[i].z<<endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll test_case=1; //cin>>test_case;
    while(test_case--)
    {
        input(), solve();
        cout<<'\n';
    }
    return 0;
}
