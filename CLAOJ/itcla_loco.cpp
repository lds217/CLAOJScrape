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



//main

long long n;int m;

struct Matrix{
	long long val[4][4];
	//contructor: run when use the struct

	Matrix()
	{
		mset(val,0);
	}
	Matrix operator * (Matrix b)
	{
		Matrix c;
		FOR(i,1,3)
			FOR(j,1,3)
			{
				c.val[i][j]=0;
				FOR(k,1,3)
					(c.val[i][j]+=val[i][k]*b.val[k][j]%m)%=m;
			}
		return c;
	}
	
	// this needs to be a pointer
	Matrix POW(long long b)
	{
		//b==1
	    if (b==1) return *this;
	    Matrix tmp=POW( b/2);
	    return (b%2==0 ? (tmp*tmp) : (tmp*tmp)* *this) ;
	}
};


Matrix base;


void input()
{

	cin>>n>>m;	
}
void lds_go_goooo()
{
	base.val[1][1]=base.val[1][2]=base.val[1][3]=base.val[2][1]=base.val[3][2]=1;

	if(n==1)
		cout<<1%m;
	else
		if(n==2)
			cout<<2%m;
		else
			if(n==3)
				cout<<4%m;
			else
			{
				base=base.POW(n-3);
				cout<<(4*base.val[1][1]+2*base.val[1][2]+1*base.val[1][3])%m;
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

//code by lds, student of yugihacker
