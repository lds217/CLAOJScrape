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

int n;

void input()
{
	ll sum=0,minn=1e9;
	ll u;
    ll ck[10000],a[10000],idk[10000];
	cin>>n;
	FOR(i,1,n)
	{
		cin>>a[i];
		ck[a[i]]++;	
		minn=min(minn,a[i]);
	}
	ll cnt=0;
	FOR(i,1,n)
		if(ck[a[i]]%2!=0)
		{
			cnt++;
			if(a[i]%2==0)
				minn=min(minn,a[i]);
		}
		else
		{
			if(idk[a[i]]!=-2)
				cnt++,idk[a[i]]=-2;;
		}
	FOR(i,1,n)
	{
		if(ck[a[i]]%2!=0)
		    sum+=(a[i]%2==0&&cnt%2!=0?a[i]-1:a[i]);
		 else
		    if(ck[a[i]]!=-2)
		        sum+=a[i],ck[a[i]]=-2;
	}
//	cout<<cnt<<endl;
	if(cnt%2==0)
		cout<<((sum-minn)%2==0?(sum-minn-1):(sum-minn));
	else
		cout<<(sum%2==0?sum-1:sum);
}
void lds_go_goooo()
{

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
