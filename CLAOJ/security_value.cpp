// Template //
#include <bits/stdc++.h>
#define FOR(i, a, b) for(ll i=a, _b=b; i<=_b; i++)
#define FORD(i, a, b) for(ll i=a, _b=b; i>=_b; i--)
#define pb push_back
#define ALL(a) a.begin(), a.end()

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
const ll maxn=5000005;
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


        // Main Function //

//main
long long n,k;
string str;

void input()
{
	cin>>n>>k>>str;
}

void lds_go_goooo()
{
	long long ans=0,maxx=0;
	FOR(i,0,str.size()-1)
	{
		long long tmp=0;
		if(str[i]>='0'&&str[i]<='9')
			tmp=str[i]-'0';
		else
			if(str[i]>='a'&&str[i]<='z')
				tmp=str[i]-'a'+1;
			else
				if(str[i]>='A'&&str[i]<='Z')
					tmp=(str[i]-'A'+1)*2;
				else
					tmp=maxx;
		ans+=tmp;
		maxx=max(maxx,tmp);
	//	cout<<tmp<<' ';
	}
	cout<<ans<<endl;	
	if(ans>=k)
		cout<<"BAO MAT";
	else
		cout<<"KHONG BAO MAT";	
}


int main()
{
 	ios_base::sync_with_stdio(false);
 	cin.tie(0);
 	cout.tie(0);
    //freopen(task".INP", "r", stdin);
    //freopen(task".OUT", "w", stdout);
    ll test_case=1; //cin>>test_case;
    while(test_case--)
    {
        input(); lds_go_goooo();
        cout<<'\n';
    }
    return 0;
}
