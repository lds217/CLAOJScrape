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

int x,y;

void input()
{
	cin>>x>>y;
}

bool upperPrime(long long x){
	if(x==0||x==1)
		return 0;
	if (x%2==0 && x>2)
		return 0;
	else if (x%3==0 && x>3)
		return 0;
	else{
		long long k = (sqrt(x)+1)/6;
		for (int i=1;i<=k;i++)
			if ((x%(6*i+1) == 0) && (6*i+1 < x))
				return 0;
			else if((x%(6*i-1) == 0) && (6*i-1 < x))
				return 0;
	}
	return 1;
}

void lds_go_goooo()
{
	FOR(i,x,y)
	{
		string tmp=to_string(i);
		//if(tmp[0]=='2'||tmp[0]=='5')	continue;
		reverse(ALL(tmp));
		long long num=stoll(tmp);
		if(upperPrime(num))
			cout<<i<<endl;
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
