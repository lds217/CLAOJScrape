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

int n,m;


string mul(string a, int b)
{
	int n=a.size();
	string tmp;
	int du=0;
	while(n--)
	{
		int num=((a[n]-'0')*b+du)%10;
		du=((a[n]-'0')*b+du)/10;
		tmp+=(char)num+'0';
	}
	if(du>=1)
		tmp+=(char)du+'0';
	reverse(ALL(tmp));
	
	return tmp;
}

string add(string a,string b)
{
	int n=max(a.size(),b.size());
	while(b.size()<n)
		b="0"+b;
	while(a.size()<n)
		a="0"+a;
		int du=0;
	string tmp;
	while(n--)
	{
		int num=((a[n]-'0')+(b[n]-'0')+du)%10;
		du=((a[n]-'0')+(b[n]-'0')+du)/10;
		tmp+=(char)num+'0';
	}
		if(du>=1)
		tmp+=(char)du+'0';
	reverse(ALL(tmp));
	
	return tmp;
}

void input()
{
	cin>>n>>m;
}
void solve()
{
	string two="1";
	FOR(i,1,n)
		two=mul(two,2);
	string three="1";
	FOR(i,1,m)
		three=mul(three,3);
	string tmp=add(two,three);
	int num=0;
	FOR(i,0,tmp.size()-1)
		num+=(tmp[i]-'0');
	cout<<num<<' ';
	cout<<tmp[0]<<tmp[1]<<tmp[2];
	
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
