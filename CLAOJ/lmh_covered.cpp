/*// Template //
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

ll x1,y_1,x2,y2,x3,y3,x4,y4;

void input()
{
	cin>>x1>>y_1>>x2>>y2>>x3>>y3>>x4>>y4;
}

void lds_go_goooo()
{
	if(x1>x3 ||(x1==x3&&x2>x4))
	{
		swap(x1,x3);
		swap(y_1,y3);
		swap(x2,x4);
		swap(y2,y4);
	}
	if( (x3<=x2&&x3>=x1&&y3>=y_1&&y3<=y_1) || (x3<=x2&&x3>=x1&&y4>=y_1&&y4<=y_1) )
		cout<<0;
	else
	if((y3>=y_1&&y3<=y2) || (y4>=y_1&&y4<=y2))
		cout<<min({(x3-x2)*(x3-x2),(x4-x2)*(x4-x2),(x3-x1)*(x3-x1),(x4-x1)*(x4-x1)});
	else
	if((x3>=x1&&x3<=x2) || (x4>=x1&&x4<=x2))
		cout<<min({(y3-y2)*(y3-y2),(y4-y2)*(y4-y2),(y3-y_1)*(y3-y_1),(y4-y_1)*(y4-y_1)}),cout<<"hi";
	else
		cout<<min({(x3-x2)*(x3-x2)+(y3-y2)*(y3-y2),(x4-x2)*(x4-x2)+(y4-y2)*(y4-y2),(x1-x3)*(x1-x3)+(y_1-y3)*(y_1-y3),
		(x4-x1)*(x4-x1)+(y4-y_1)*(y4-y_1),(y_1-y4)*(y_1-y4)+(x2-x3)*(x2-x3)});
		
}

int main()
{
 	ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen(task".INP", "r", stdin);
    //freopen(task".OUT", "w", stdout);
    ll test_case=1; cin>>test_case;
    while(test_case--)
    {
        input(), lds_go_goooo();
        cout<<'\n';
    }
    return 0;
}
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

ll x1,y_1,x2,y2,x3,y3,x4,y4;

void input()
{
	cin>>x1>>y_1>>x2>>y2>>x3>>y3>>x4>>y4;
}

void lds_go_goooo()
{
	if(x1>x3 ||(x1==x3&&x2>x4))
	{
		swap(x1,x3);
		swap(y_1,y3);
		swap(x2,x4);
		swap(y2,y4);
	}
	if( (x3<=x2&&x3>=x1&&y3>=y_1&&y3<=y_1) || (x3<=x2&&x3>=x1&&y4>=y_1&&y4<=y_1) )
		cout<<0;
	else
	if((y3>=y_1&&y3<=y2) || (y4>=y_1&&y4<=y2))
		cout<<min({(x3-x2)*(x3-x2),(x4-x2)*(x4-x2),(x3-x1)*(x3-x1),(x4-x1)*(x4-x1)});
	else
	if((x3>=x1&&x3<=x2) || (x4>=x1&&x4<=x2))
		cout<<min({(y3-y2)*(y3-y2),(y4-y2)*(y4-y2),(y3-y_1)*(y3-y_1),(y4-y_1)*(y4-y_1)}),cout<<"hi";
	else
		cout<<min({(x3-x2)*(x3-x2)+(y3-y2)*(y3-y2),(x4-x2)*(x4-x2)+(y4-y2)*(y4-y2),(x1-x3)*(x1-x3)+(y_1-y3)*(y_1-y3),
		(x4-x1)*(x4-x1)+(y4-y_1)*(y4-y_1),(y_1-y4)*(y_1-y4)+(x2-x3)*(x2-x3)});
		
}

int main()
{
 	ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen(task".INP", "r", stdin);
    //freopen(task".OUT", "w", stdout);
    ll test_case=1; cin>>test_case;
    while(test_case--)
    {
        input(), lds_go_goooo();
        cout<<'\n';
    }
    return 0;
}
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

ll x1,y_1,x2,y2,x3,y3,x4,y4;

void input()
{
	cin>>x1>>y_1>>x2>>y2>>x3>>y3>>x4>>y4;
}

void lds_go_goooo()
{
	if(x1>x3 ||(x1==x3&&x2>x4))
	{
		swap(x1,x3);
		swap(y_1,y3);
		swap(x2,x4);
		swap(y2,y4);
	}
	if( (x3<=x2&&x3>=x1&&y3>=y_1&&y3<=y_1) || (x3<=x2&&x3>=x1&&y4>=y_1&&y4<=y_1) )
		cout<<0;
	else
	if((y3>=y_1&&y3<=y2) || (y4>=y_1&&y4<=y2))
		cout<<min({(x3-x2)*(x3-x2),(x4-x2)*(x4-x2),(x3-x1)*(x3-x1),(x4-x1)*(x4-x1)});
	else
	if((x3>=x1&&x3<=x2) || (x4>=x1&&x4<=x2))
		cout<<min({(y3-y2)*(y3-y2),(y4-y2)*(y4-y2),(y3-y_1)*(y3-y_1),(y4-y_1)*(y4-y_1)}),cout<<"hi";
	else
		cout<<min({(x3-x2)*(x3-x2)+(y3-y2)*(y3-y2),(x4-x2)*(x4-x2)+(y4-y2)*(y4-y2),(x1-x3)*(x1-x3)+(y_1-y3)*(y_1-y3),
		(x4-x1)*(x4-x1)+(y4-y_1)*(y4-y_1),(y_1-y4)*(y_1-y4)+(x2-x3)*(x2-x3)});
		
}

int main()
{
 	ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen(task".INP", "r", stdin);
    //freopen(task".OUT", "w", stdout);
    ll test_case=1; cin>>test_case;
    while(test_case--)
    {
        input(), lds_go_goooo();
        cout<<'\n';
    }
    return 0;
}
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

ll x1,y_1,x2,y2,x3,y3,x4,y4;

void input()
{
	cin>>x1>>y_1>>x2>>y2>>x3>>y3>>x4>>y4;
}

void lds_go_goooo()
{
	if(x1>x3 ||(x1==x3&&x2>x4))
	{
		swap(x1,x3);
		swap(y_1,y3);
		swap(x2,x4);
		swap(y2,y4);
	}
	if( (x3<=x2&&x3>=x1&&y3>=y_1&&y3<=y_1) || (x3<=x2&&x3>=x1&&y4>=y_1&&y4<=y_1) )
		cout<<0;
	else
	if((y3>=y_1&&y3<=y2) || (y4>=y_1&&y4<=y2))
		cout<<min({(x3-x2)*(x3-x2),(x4-x2)*(x4-x2),(x3-x1)*(x3-x1),(x4-x1)*(x4-x1)});
	else
	if((x3>=x1&&x3<=x2) || (x4>=x1&&x4<=x2))
		cout<<min({(y3-y2)*(y3-y2),(y4-y2)*(y4-y2),(y3-y_1)*(y3-y_1),(y4-y_1)*(y4-y_1)}),cout<<"hi";
	else
		cout<<min({(x3-x2)*(x3-x2)+(y3-y2)*(y3-y2),(x4-x2)*(x4-x2)+(y4-y2)*(y4-y2),(x1-x3)*(x1-x3)+(y_1-y3)*(y_1-y3),
		(x4-x1)*(x4-x1)+(y4-y_1)*(y4-y_1),(y_1-y4)*(y_1-y4)+(x2-x3)*(x2-x3)});
		
}

int main()
{
 	ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen(task".INP", "r", stdin);
    //freopen(task".OUT", "w", stdout);
    ll test_case=1; cin>>test_case;
    while(test_case--)
    {
        input(), lds_go_goooo();
        cout<<'\n';
    }
    return 0;
}
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

ll x1,y_1,x2,y2,x3,y3,x4,y4;

void input()
{
	cin>>x1>>y_1>>x2>>y2>>x3>>y3>>x4>>y4;
}

void lds_go_goooo()
{
	if(x1>x3 ||(x1==x3&&x2>x4))
	{
		swap(x1,x3);
		swap(y_1,y3);
		swap(x2,x4);
		swap(y2,y4);
	}
	if( (x3<=x2&&x3>=x1&&y3>=y_1&&y3<=y_1) || (x3<=x2&&x3>=x1&&y4>=y_1&&y4<=y_1) )
		cout<<0;
	else
	if((y3>=y_1&&y3<=y2) || (y4>=y_1&&y4<=y2))
		cout<<min({(x3-x2)*(x3-x2),(x4-x2)*(x4-x2),(x3-x1)*(x3-x1),(x4-x1)*(x4-x1)});
	else
	if((x3>=x1&&x3<=x2) || (x4>=x1&&x4<=x2))
		cout<<min({(y3-y2)*(y3-y2),(y4-y2)*(y4-y2),(y3-y_1)*(y3-y_1),(y4-y_1)*(y4-y_1)}),cout<<"hi";
	else
		cout<<min({(x3-x2)*(x3-x2)+(y3-y2)*(y3-y2),(x4-x2)*(x4-x2)+(y4-y2)*(y4-y2),(x1-x3)*(x1-x3)+(y_1-y3)*(y_1-y3),
		(x4-x1)*(x4-x1)+(y4-y_1)*(y4-y_1),(y_1-y4)*(y_1-y4)+(x2-x3)*(x2-x3)});
		
}

int main()
{
 	ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen(task".INP", "r", stdin);
    //freopen(task".OUT", "w", stdout);
    ll test_case=1; cin>>test_case;
    while(test_case--)
    {
        input(), lds_go_goooo();
        cout<<'\n';
    }
    return 0;
}
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

ll x1,y_1,x2,y2,x3,y3,x4,y4;

void input()
{
	cin>>x1>>y_1>>x2>>y2>>x3>>y3>>x4>>y4;
}

void lds_go_goooo()
{
	if(x1>x3 ||(x1==x3&&x2>x4))
	{
		swap(x1,x3);
		swap(y_1,y3);
		swap(x2,x4);
		swap(y2,y4);
	}
	if( (x3<=x2&&x3>=x1&&y3>=y_1&&y3<=y_1) || (x3<=x2&&x3>=x1&&y4>=y_1&&y4<=y_1) )
		cout<<0;
	else
	if((y3>=y_1&&y3<=y2) || (y4>=y_1&&y4<=y2))
		cout<<min({(x3-x2)*(x3-x2),(x4-x2)*(x4-x2),(x3-x1)*(x3-x1),(x4-x1)*(x4-x1)});
	else
	if((x3>=x1&&x3<=x2) || (x4>=x1&&x4<=x2))
		cout<<min({(y3-y2)*(y3-y2),(y4-y2)*(y4-y2),(y3-y_1)*(y3-y_1),(y4-y_1)*(y4-y_1)}),cout<<"hi";
	else
		cout<<min({(x3-x2)*(x3-x2)+(y3-y2)*(y3-y2),(x4-x2)*(x4-x2)+(y4-y2)*(y4-y2),(x1-x3)*(x1-x3)+(y_1-y3)*(y_1-y3),
		(x4-x1)*(x4-x1)+(y4-y_1)*(y4-y_1),(y_1-y4)*(y_1-y4)+(x2-x3)*(x2-x3)});
		
}

int main()
{
 	ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen(task".INP", "r", stdin);
    //freopen(task".OUT", "w", stdout);
    ll test_case=1; cin>>test_case;
    while(test_case--)
    {
        input(), lds_go_goooo();
        cout<<'\n';
    }
    return 0;
}
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

ll x1,y_1,x2,y2,x3,y3,x4,y4;

void input()
{
	cin>>x1>>y_1>>x2>>y2>>x3>>y3>>x4>>y4;
}

void lds_go_goooo()
{
	if(x1>x3 ||(x1==x3&&x2>x4))
	{
		swap(x1,x3);
		swap(y_1,y3);
		swap(x2,x4);
		swap(y2,y4);
	}
	if( (x3<=x2&&x3>=x1&&y3>=y_1&&y3<=y_1) || (x3<=x2&&x3>=x1&&y4>=y_1&&y4<=y_1) )
		cout<<0;
	else
	if((y3>=y_1&&y3<=y2) || (y4>=y_1&&y4<=y2))
		cout<<min({(x3-x2)*(x3-x2),(x4-x2)*(x4-x2),(x3-x1)*(x3-x1),(x4-x1)*(x4-x1)});
	else
	if((x3>=x1&&x3<=x2) || (x4>=x1&&x4<=x2))
		cout<<min({(y3-y2)*(y3-y2),(y4-y2)*(y4-y2),(y3-y_1)*(y3-y_1),(y4-y_1)*(y4-y_1)}),cout<<"hi";
	else
		cout<<min({(x3-x2)*(x3-x2)+(y3-y2)*(y3-y2),(x4-x2)*(x4-x2)+(y4-y2)*(y4-y2),(x1-x3)*(x1-x3)+(y_1-y3)*(y_1-y3),
		(x4-x1)*(x4-x1)+(y4-y_1)*(y4-y_1),(y_1-y4)*(y_1-y4)+(x2-x3)*(x2-x3)});
		
}

int main()
{
 	ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen(task".INP", "r", stdin);
    //freopen(task".OUT", "w", stdout);
    ll test_case=1; cin>>test_case;
    while(test_case--)
    {
        input(), lds_go_goooo();
        cout<<'\n';
    }
    return 0;
}
*/
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

ll x1,y_1,x2,y2,x3,y3,x4,y4;

void input()
{
	cin>>x1>>y_1>>x2>>y2>>x3>>y3>>x4>>y4;
}

void lds_go_goooo()
{
	if(x1>x3 ||(x1==x3&&x2>x4))
	{
		swap(x1,x3);
		swap(y_1,y3);
		swap(x2,x4);
		swap(y2,y4);
	}
	if( (x3<=x2&&x3>=x1&&y3>=y_1&&y3<=y_1) || (x3<=x2&&x3>=x1&&y4>=y_1&&y4<=y_1) )
		cout<<0;
	else
	if((y3>=y_1&&y3<=y2) || (y4>=y_1&&y4<=y2))
		cout<<min({(x3-x2)*(x3-x2),(x4-x2)*(x4-x2),(x3-x1)*(x3-x1),(x4-x1)*(x4-x1)});
	else
	if((x3>=x1&&x3<=x2) || (x4>=x1&&x4<=x2))
		cout<<min({(y3-y2)*(y3-y2),(y4-y2)*(y4-y2),(y3-y_1)*(y3-y_1),(y4-y_1)*(y4-y_1)});
	else
		cout<<min({(x3-x2)*(x3-x2)+(y3-y2)*(y3-y2),(x4-x2)*(x4-x2)+(y4-y2)*(y4-y2),(x1-x3)*(x1-x3)+(y_1-y3)*(y_1-y3),
		(x4-x1)*(x4-x1)+(y4-y_1)*(y4-y_1),(y_1-y4)*(y_1-y4)+(x2-x3)*(x2-x3)});
		
}

int main()
{
 	ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen(task".INP", "r", stdin);
    //freopen(task".OUT", "w", stdout);
    ll test_case=1; cin>>test_case;
    while(test_case--)
    {
        input(), lds_go_goooo();
        cout<<'\n';
    }
    return 0;
}
