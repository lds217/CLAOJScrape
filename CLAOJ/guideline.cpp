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
int n,k,c;
vector <ll> cy,cx;


	
// 
// 0 0 0 0 0 0 




void input()
{
	cx.pb(-2e9);
	cy.pb(-2e9);
cin>>n>>k>>c;
	FOR(i,1,n)
	{
		ll type,r;
		cin>>type>>r;
		if(type)
			cy.pb(r);
		else
			cx.pb(r);
	}
	sort(ALL(cy));
	cy.erase( unique( ALL(cy) ), cy.end() );
	sort(ALL(cx));
	cx.erase( unique( ALL(cx) ), cx.end() );
    //FOR(i,1,cy.size()-1)
    //    if(cy[i]==cy[i-1])
    //        cout<<1;
	cy.pb(3000000000);
	cx.pb(3000000000);

}
void lds_go_goooo()
{
//	for(ll i: cy)	cout<<i <<' ';
//	cout<<endl;
	//for(ll i: cx)	cout<<i <<' ';
//	cout<<endl;
	FOR(i,1,k)
	{
		ll x,y,x2,y2;
		cin>>x>>y>>x2>>y2;
		ll l_x=upper_bound(ALL(cx),x)-cx.begin()-1;
		ll r_x=lower_bound(ALL(cx),x2)-cx.begin();
		ll u_y=lower_bound(ALL(cy),y2)-cy.begin();
		ll d_y=upper_bound(ALL(cy),y)-cy.begin()-1;
		if(x-cx[l_x]<=c||cx[r_x]-x2<=c||cy[u_y]-y2<=c||y-cy[d_y]<=c)
			cout<<"YES";
		else
			cout<<"NO";
		cout<<endl;
	}
}
/*4 9 1
0 96
1 50
0 100
0 66
84 2 92 36
79 20 99 49
37 4 37 62
8 16 40 78
24 50 49 66
75 24 100 88
93 29 94 56
69 33 82 71
68 53 78 61*/

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
