#include <utility>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <unordered_map>
#include <map>
#include <iomanip>
#include <vector>
#include <iostream>
// Template //
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
const ll maxn=1e6+2;
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
void dectobin(long long u,string &k)
{
    while(u>0)
    {
        k+=(char)(u%2+'0');
        u/=2;
    }
    reverse(ALL(k));
}

string k="",s;
void input()
{
    long long u;
    cin>>u;
    dectobin(u,k);
    cin>>s;
    //cout<<k<<endl;
}

bool compare(string &a,string &b)
{
    if(a.size()>b.size()) return true;
    if(a.size()==b.size()) 
        FOR(i,1,a.size()-1)
        {
            if(a[i]>b[i]) return true;
            else   
                if(a[i]<b[i]) 
                    return false;
        }
    else
        return false;
    return false;
}

void lds_go_goooo()
{
    
    if(s.size()<k.size())
    {
        cout<<0;
        return;
    }
    if(s.size()==k.size())
    {
        if(compare(k,s))
        {
            cout<<0;
            return;
        }
    }
            int luu=s.size()-k.size(),left=luu;
            FOR(i,1,s.size()-1)
               if(s[i]=='1'&&left)
                    s.erase(i,1),left--,i--;
           // cout<<s<<endl;
            //cout<<k<<endl;
            if(left)
            {
                cout<<luu;
                return;
            }
            else
                FOR(i,0,k.size()-1)
                    if(k[i]!=s[i])
                    {
                        cout<<luu+(k[i]<s[i]);
                        return;
                    }
            cout<<luu;

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
        cout<<endl;
    }
    return 0;
}

/*


 d8b d8b
888888888
`Y88888P'       "Heart"
 `Y888P'      Le Thanh Dat
  `Y8P'
   `Y'
   
*/
