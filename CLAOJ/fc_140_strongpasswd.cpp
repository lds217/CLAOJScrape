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

string str;
bool len,up,low,num,spec,dupl=1;

string specialcharater="!@#$%^&*()-+";

void input()
{
	cin>>str;
}
void lds_go_goooo()
{
	if(str.size()>=8)
		len=1;
	FOR(i,0,str.size()-1)
	{
		if(str[i]>='0'&&str[i]<='9')
			num=1;
		if(str[i]>='a'&&str[i]<='z')
			low=1;
		if(str[i]>='A'&&str[i]<='Z')
			up=1;
		if(spec==0)
			for(char a:specialcharater)
				if(str[i]==a)
				{
					spec=1;
					break;	
				}
		if(str[i]==str[i+1])
			dupl=0;
	}
	if(len==1&&up==1&&low==1&&num==1&&spec==1&&dupl==1)
		cout<<"YES";
	else
		cout<<"NO";
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
