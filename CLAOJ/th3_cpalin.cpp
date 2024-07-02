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
#define task ""

using namespace std;
typedef int64_t ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
const ll maxn=1000111;
const ll MOD=1e9+3;
const ll base=31;
const ll inf=1e18;


bool maximize(ll &A, ll B)
{
    return A<B ? A=B, true : false;
}

bool minimize(ll &A, ll B)
{
    return A>B ? A=B, true : false;
}

        // Main Function //
ll POW[maxn],hashT[maxn],POWrev[maxn],hashrev[maxn];
int n;
string T;
void input()
{
    cin>>T;
}

ll getHashT(int i, int j){
    return (hashT[j]-hashT[i-1]*POW[j-i+1]+MOD*MOD)%MOD;
}

ll getHashrev(int i, int j){
    return (hashrev[i]-hashrev[j+1]*POWrev[n-(j-i)] +MOD*MOD )%MOD;
}


void solve()
{
    n=T.size();
    T=" "+T;

    POW[0]=1;
    FOR(i,1,n)POW[i]=(POW[i-1]*base)%MOD;
    FOR(i,1,n)hashT[i]=(hashT[i-1]*base + T[i]-'a'+1)%MOD;

    POWrev[n+1]=1;
    FORD(i,n,1)POWrev[i] =(POWrev[i+1]*base)%MOD;
    FORD(i,n,1) hashrev[i]=(hashrev[i+1]*base+T[i]-'a'+1)%MOD;
    int l,r,q;
    cin>>q;
    while(q--)
    {
        cin>>l>>r;
        if(getHashT(l,r)==getHashrev(l,r))
            cout<<"yes";
        else
            cout<<"no";
        cout<<endl;
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
   // freopen(task".INP", "r", stdin);
   // freopen(task".OUT", "w", stdout);
    ll test_case=1; //cin>>test_case;
    while(test_case--)
    {
        input(), solve();
        cout<<'\n';
    }
    return 0;
}
