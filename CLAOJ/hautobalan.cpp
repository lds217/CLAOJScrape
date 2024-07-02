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
const ll maxn=1e2+2;
const ll mod=26051968;
const ll inf=1e18;


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

string bt;
stack <double> num;
void input()
{
    getline(cin,bt);

}

void solve()
{
     FOR(i,0,bt.size()-1)
     if(bt[i]=='-'&&bt[i+1]>='0'&&bt[i+1]<='9')
     {
         i++;
         string tmp="";tmp+=bt[i];
            while((bt[i]>='0'&&bt[i]<='9')||(bt[i]=='.'))
            {
                i++;
                tmp+=bt[i];
            }
            num.push(-stod(tmp));
     }
     else
        if(bt[i]>='0'&&bt[i]<='9')
        {
             string tmp="";tmp+=bt[i];
            while((bt[i]>='0'&&bt[i]<='9')||(bt[i]=='.'))
            {
                i++;
                tmp+=bt[i];
            }
            num.push(stod(tmp));

        }
        else
            if(bt[i]!=' ')
            {
                ld a=num.top();
                num.pop();
                ld b=num.top();
                num.pop();
                if(bt[i]=='+')
                    num.push(b+a);
                if(bt[i]=='-')
                    num.push(b-a);
                if(bt[i]=='*')
                    num.push(b*a);
                if(bt[i]=='/')
                    num.push(b/a);
            }
            cout<<setprecision(3)<<fixed<<num.top();
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
