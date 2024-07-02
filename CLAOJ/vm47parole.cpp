// Template //
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <unordered_set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <cmath>
#include <array>
#include <cassert>
#include <random>
#include <unistd.h>
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
const ll maxn=3*1e5+2;
const ll mod=1e9+7;
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

const int base=37;

string s,t;
ll prehash[maxn],suffhash[maxn],poww[maxn];
int n;
void input()
{
	cin>>s;
	n=s.size();
	s=' '+s;
}

int getprehash(int l, int r)
{
	return (prehash[r]-prehash[l-1]*poww[r-l+1]+mod*mod)%mod;
}

int getsuffhash(int r,int l)
{
	return (suffhash[r]-suffhash[l+1]*poww[l-r+1]+mod*mod)%mod;
}

void lds_go_goooo()
{
	poww[0]=1;
	FOR(i,1,n)
	{
		poww[i]=(poww[i-1]*base) %mod;
		prehash[i]=(prehash[i-1]*base+(s[i]-'a'+1))%mod;
	}
	FORD(i,n,1)
		suffhash[i]=(suffhash[i+1]*base+(s[i]-'a'+1))%mod;
	//abcb
	//cout<<getprehash(2,2)<<' '<<suffhash[3]<<endl;
	ll ans=inf;
	FORD(i,n,1)
	{
		if(getprehash(i-(n-i),i)==suffhash[i])	minimize(ans,2*i-n-1);
		if(getprehash(i-(n-i)-1,i-1)==suffhash[i])	minimize(ans,2*(i-1)-n);
	}
    ll ans2=inf;
   // cout<<prehash[2]<<' '<<getsuffhash(2,3)<<endl;
    FOR(i,1,n)
    {
        if(prehash[i]==getsuffhash(i,i+i-1))  minimize(ans2,n-(2*i-1));
        if(prehash[i]==getsuffhash(i+1,i+i))  minimize(ans2,n-2*i);
    }

    //cout<<ans<<' '<<ans2<<endl;
    if(ans==inf)
        ans=1;
    if(ans2==inf)
        ans2=1;
    if(ans>=ans2)
    {
       FORD(i,n,n-ans2+1)
            cout<<s[i];
        FOR(i,1,n)
            cout<<s[i];
    }
    else
    {
         FOR(i,1,n)	cout<<s[i];
        FORD(i,ans,1)
            cout<<s[i];
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
