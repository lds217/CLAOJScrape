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
const ll maxn=2*1e5+2;
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
const double EPS = 1e-9;
const int INF = 2;


int gauss (vector < vector<double> > a, vector<double> & ans) {
    int n = (int) a.size();
    int m = (int) a[0].size() - 1;

    vector<int> where (m, -1);
    for (int col=0, row=0; col<m && row<n; ++col) {
        int sel = row;
        for (int i=row; i<n; ++i)
            if (abs (a[i][col]) > abs (a[sel][col]))
                sel = i;
        if (abs (a[sel][col]) < EPS)
            continue;
        for (int i=col; i<=m; ++i)
            swap (a[sel][i], a[row][i]);
        where[col] = row;

        for (int i=0; i<n; ++i)
            if (i != row) {
                double c = a[i][col] / a[row][col];
                for (int j=col; j<=m; ++j)
                    a[i][j] -= a[row][j] * c;
            }
        ++row;
    }

    ans.assign (m, 0);
    for (int i=0; i<m; ++i)
        if (where[i] != -1)
            ans[i] = a[where[i]][m] / a[where[i]][i];
    for (int i=0; i<n; ++i) {
        double sum = 0;
        for (int j=0; j<m; ++j)
            sum += ans[j] * a[i][j];
        if (abs (sum - a[i][m]) > EPS)
            return 0;
    }

    for (int i=0; i<m; ++i)
        if (where[i] == -1)
            return INF;
    return 1;
}

struct point{
	double x,y,z;
} A,a[maxn];

ll n,k;
void input()
{
	cin>>n;
	cin>>A.x>>A.y>>A.z;
	FOR(i,1,n)
		cin>>a[i].x>>a[i].y>>a[i].z;	
}


ld dist(point x, point y)
{
    return sqrt((x.x-y.x)*(x.x-y.x) + (x.y-y.y)*(x.y-y.y) + (x.z-y.z)*(x.z-y.z));
}


double tinh(point a,point b)
{
	return (a.x*a.x+a.y*a.y+a.z*a.z)-(b.x*b.x+b.y*b.y+b.z*b.z);
}

void lds_go_goooo()
{

	point x=a[1],y=a[2],w=a[3],z=a[4];
	vector <vector <double> > b(3,vector<double> (4,0));
	b[0][0]=(-2*x.x+2*y.x);
	b[0][1]=(-2*x.y+2*y.y);
	b[0][2]=(-2*x.z+2*y.z);
	b[0][3]=(tinh(x,y));
	
	b[1][0]=(-2*x.x+2*w.x);
	b[1][1]=(-2*x.y+2*w.y);
	b[1][2]=(-2*x.z+2*w.z);
	b[1][3]=(tinh(x,w));
	
	b[2][0]=(-2*x.x+2*z.x);
	b[2][1]=(-2*x.y+2*z.y);
	b[2][2]=(-2*x.z+2*z.z);
	b[2][3]=(tinh(x,z));
	
	vector <double> ans(4,0);
	gauss (b,ans);
	point res;
	res.x=-ans[0];
	res.y=-ans[1];
	res.z=-ans[2];

	//cout<<res.x<<' '<<res.y<<' '<<res.z<<endl;
	cout<<setprecision(2)<<fixed<<dist(A,res)-dist(res,x);	
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
