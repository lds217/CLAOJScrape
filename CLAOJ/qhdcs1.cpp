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
#define task ""
 
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
 
ll arr[1001];
ll dp[11][100][3];
string L,R;
bool eratos[250];
 
void prepare()
{
    mset(eratos,true);
    FOR(i,2,250)
        if(eratos[i]==1)
        	for(int j=i*i;j<=250;j+=i)
                eratos[j]=0;
    eratos[0]=eratos[1]=0;
}
 
ll get(ll pos,ll n,ll sum, bool ok)
{
    if(pos>n)   return eratos[sum];
    if(dp[pos][sum][ok]!=-1) return dp[pos][sum][ok];
    ll limit=9;
    if(ok==0)
        limit=arr[pos];
    ll res=0;
    FOR(i,0,limit)
        if(ok==1||i<limit)
            res+=get(pos+1,n,sum+i,1);
        else
            res+=get(pos+1,n,sum+i,0);
    return dp[pos][sum][ok]=res;
}
 
ll solve(string str)
{
    mset(arr,0);
    mset(dp,-1);
    FOR(i,0,str.size()-1)
        arr[i+1]=str[i]-'0';
    return get(1,str.size(),0,0);
}
 
ll digitsum(string str)
{
    ll sum=0;
        for(char a :str)
          sum+=a-'0';
    return sum;
}
 
int main()
{
 	ios_base::sync_with_stdio(false);
    cin.tie(0);
    #define task "chiahet"
    prepare();
    freopen(task".INP", "r", stdin);
    freopen(task".OUT", "w", stdout);
     cin>>L>>R;
     cout<<solve(R)-solve(to_string(stoi(L)-1))<<endl;
    return 0;
}
