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


using namespace std;
typedef int64_t ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
const ll maxn=2*1e6+2;
const ll MOD = 1e9 + 7;
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

#define int long long

//main
long long n,k;
long long f[maxn];
long long m;
struct Matrix{
	long long val[3][3];
	//contructor: run when use the struct

	Matrix()
	{
		mset(val,0);
	}
	Matrix operator * (Matrix b)
	{
		Matrix c;
		FOR(i,1,2)
			FOR(j,1,2)
			{
				c.val[i][j]=0;
				FOR(k,1,2)
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

long long i;
long long pos[maxn];

void input()
{
	cin>>n>>i>>k;
	m=k;
	mset(f,0);
}
void lds_go_goooo()
{
	Matrix base;

	base.val[1][1]=base.val[1][2]=base.val[2][1]=1;
	f[1]=base.POW(i-1).val[1][1]%k;
	f[2]=base.POW(i).val[1][1]%k;

	FOR(ind,3,n)
		f[ind]=(f[ind-1]+f[ind-2])%k;
/*	
	cout<<"index :";
	FOR(ind,i,i+n)
		cout<<ind<<' ';
	cout<<endl;
	cout<<"value :";
	FOR(ind,1,n)
		cout<<f[ind]<<" ";
	cout<<endl;*/
	mset(pos,-1);
	pos[0]=0;
	long long cur=0;
	FOR(ind,1,n)
	{

		cur=(cur+f[ind])%k;
		if(pos[cur]!=-1)
		{
			if(cur==0)
			{
				cout<<ind<<' ';
				FOR(j,1,ind)	cout<< j+i-1<<' ';
			}
			else
			{
				cout<<ind-pos[cur]<<' ';
				FOR(j,pos[cur]+1,ind)
					cout<<j+i-1<<' ';
			}
			return;
		}
		else
			pos[cur]=ind;
	}
	cout<<0;
	return;
			
}
#define task "3"
signed main()
{
 	//ios_base::sync_with_stdio(false);
    //cin.tie(0);

    ll test_case=1; cin>>test_case;
    while(test_case--)
    {
        input(), lds_go_goooo();
        cout<<endl;
    }
    return 0;
}
