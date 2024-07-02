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
#define task "RAONE"
 
using namespace std;
typedef long long ll;
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
 
ll dp[12][2][100][100],arr[100];
string A,B;
int sz=0;
 
void input()
{
	cin>>A>>B;
}
 
long long get(int pos, bool smaller, int odd, int even)
{
	if(pos==sz)
		return((even-odd)==1);
		
 
	if(dp[pos][smaller][odd][even]!=-1)	
		return dp[pos][smaller][odd][even];
	ll ans=0;
	if(smaller==1)
		FOR(i,0,9)
			if(pos%2==0)
				ans+=get(pos+1,1,odd,even+i);
			else
				ans+=get(pos+1,1,odd+i,even);	
	else
	{
		for(int i=0;i<arr[pos];i++)
		{
			if(pos%2==0)
				ans+=get(pos+1,1,odd,even+i);
			else
				ans+=get(pos+1,1,odd+i,even);
		}
		if(pos%2==0)
			ans+=get(pos+1,0,odd,even+arr[pos]);
		else
			ans+=get(pos+1,0,odd+arr[pos],even);
	}
	return dp[pos][smaller][odd][even]=ans;	
}
 
long long solve(string str)
{
 
	mset(dp,-1);
	mset(arr,0);
	FOR(i,0,str.size()-1)
		arr[8-str.size()+i]=str[i]-'0';
	sz=8;
	return get(0,0,0,0);
}              
 
 
int main()
{
 	ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen(task".INP", "r", stdin);
    freopen(task".OUT", "w", stdout);
    ll test_case=1; //cin>>test_case;
    while(test_case--)
    {
        input();
        cout<<solve(B)-solve(to_string(stoi(A)-1));
 
 
        cout<<'\n';
    }
    return 0;
}
