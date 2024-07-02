// Template //
#include <iostream>
#include <cmath>
#include <algorithm>
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
#define task "ROAD"

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
struct point{
    double x,y;
};

point a,b,c;
bool inter(point Q,point P,point C)
{

    double a = Q.y - P.y;
     double b = P.x - Q.x;
    double c = a * (P.x) + b * (P.y);
    if(a*C.x+b*C.y==c)
        return true;
    else
        return false;
}


bool halfbot(point Q,point P,point C)
{
  //  y=ax+b

    double a = (P.y-Q.y)/(P.x-Q.x);
    double b =(Q.y-a*Q.x);
   // cout<<a<<b;
    if(a>0)
    {
        if(C.y-a*C.x>b)
            return false;
        else
            return true;
    }
    else
        if(C.y-a*C.x<b)
            return true;
        else
            return false;

}

void input()
{
    cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y;
}



void solve()
{
    if(a.x==b.x&&a.y<b.y)
        if(c.x<a.x)
                cout<<"LEFT";
        else
            if(c.x>a.x)
                cout<<"RIGHT";
            else
                cout<<"TOWARDS";
    else
        if(a.x==b.x&&a.y>b.y)
                if(c.x<a.x)
                        cout<<"RIGHT";
                else
                    if(c.x>a.x)
                        cout<<"LEFT";
                    else
                        cout<<"TOWARDS";
        else
            if(a.y==b.y&&a.x<b.x)
                if(c.y>a.y)
                    cout<<"LEFT";
                else
                    if(c.y<a.y)
                        cout<<"RIGHT";
                    else
                        cout<<"TOWARDS";
            else
                if(a.y==b.y&&a.x>b.x)
                    if(c.y>a.y)
                        cout<<"RIGHT";
                    else
                        if(c.y<a.y)
                            cout<<"LEFT";
                        else
                            cout<<"TOWARDS";
                else
                    if(a.x<b.x&&a.y>b.y)
                        if(inter(a,b,c))
                            cout<<"TOWARDS";
                        else
                            if(halfbot(a,b,c))
                                cout<<"RIGHT";
                            else
                                cout<<"LEFT";
                    else
                        if(a.x>b.x&&a.y<b.y)
                            if(inter(a,b,c))
                                cout<<"TOWARDS";
                            else
                                if(halfbot(a,b,c))
                                    cout<<"LEFT";
                                else
                                    cout<<"RIGHT";
                        else
                            if(a.x<b.x&&a.y<b.y)
                                if(inter(a,b,c))
                                    cout<<"TOWARDS";
                                else
                                    if(halfbot(a,b,c))
                                        cout<<"RIGHT";
                                    else
                                        cout<<"LEFT";
                            else
                                if(a.x>b.x&&a.y>b.y)
                                    if(inter(a,b,c))
                                        cout<<"TOWARDS";
                                    else
                                        if(halfbot(a,b,c))
                                            cout<<"LEFT";
                                        else
                                            cout<<"RIGHT";
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
        input(), solve();
        cout<<'\n';
    }
    return 0;
}
