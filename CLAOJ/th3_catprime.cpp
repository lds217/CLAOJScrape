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
#define task "CATPRIME"

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


bool upperPrime(string str){
	
	long long x=stoll(str);
	if(x==0||x==1)
		return 0;
	if (x%2==0 && x>2)
		return 0;
	
	else if (x%3==0 && x>3)
		return 0;
	else{
		for(int i=5;i*i<=x;i++)
		    if(x%i==0)
		        return 0;
	}
	return 1;
}

ll d;
long long a;

void input()
{
	cin>>d>>a;
}

void lds_go_goooo()
{
	ll szz=ceil(log10(a));
	if(szz<2*d)
		a=pow(10,2*d-1);
	while(1)
	{
		if(a%2==0||a%5==0)
		{
			a++;
			continue;
		}
		string str=to_string(a);
		long long sz=str.size();
		FOR(i,d,sz-1)
		{
			string tmp1=str.substr(0,sz-i);
			string tmp2=str.substr(sz-i,i);
		//	cout<<tmp1<<' '<<tmp2<<endl;
			if(tmp1.size()>=d&&tmp2.size()>=d)
				if(upperPrime(tmp1)&&upperPrime(tmp2)&&tmp2[0]!='0')
			{
				cout<<str;
				return;
			}
		}
		a++;
	}
		
	
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
        input(), lds_go_goooo();
        cout<<'\n';
    }
    return 0;
}
