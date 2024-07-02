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

string a[maxn];
int n,m,curx,cury;
vector <int> col[maxn],row[maxn];

void prepare()
{
	FOR(i,1,n)
	{
		col[i].push_back(0);
		row[i].push_back(0);
		col[i].push_back(n+1);
		row[i].push_back(n+1);
		sort(ALL(col[i]));
		sort(ALL(row[i]));
	}
	
}

void input()
{
	cin>>n>>m;
	FOR(i,1,n)
	{
		cin>>a[i];
		a[i]='.'+a[i];
		FOR(j,1,n)
		{
	 		if(a[i][j]=='L')
				curx=i,cury=j,a[i][j]='.';
			if(a[i][j]=='X')
			{
				col[j].push_back(i);
				row[i].push_back(j);
			}
		}
	}
}

void rotateMatrix()
{
	int N=n;
    for (int x = 0; x < N / 2; x++) {
        for (int y = x; y < N - x - 1; y++) {
            char temp = a[x+1][y+1];
            a[x+1][y+1] = a[y+1][N  - x];
            a[y+1][N  - x] = a[N  - x][N  - y];
            a[N  - x][N  - y] = a[N  - y][x+1];
             a[N  - y][x+1] = temp;
        }
    }
}

void solve()
{
	prepare();
	int rot=0;
	FOR(i,1,m)
	{
		char s;
		cin>>s;
		if(s=='D')
			rot--;
		else
			rot++;
		if(rot>4||rot<-4)
			rot%=4;
		if(rot==2||rot==-2)
		{
			curx=col[cury][upper_bound(col[cury].begin(),col[cury].end(),curx)-col[cury].begin()-1];
			curx++;
		}
		if(rot==4||rot==-4||rot==0)
		{
			curx=col[cury][upper_bound(col[cury].begin(),col[cury].end(),curx)-col[cury].begin()];
			curx--;
		}
		if(rot==-1||rot==3)
		{
			cury=row[curx][upper_bound(row[curx].begin(),row[curx].end(),cury)-row[curx].begin()];
			cury--;
		}
		if(rot==-3||rot==1)
		{
			cury=row[curx][upper_bound(row[curx].begin(),row[curx].end(),cury)-row[curx].begin()-1];
			cury++;
		}
	}
	a[curx][cury]='L';
	if(rot<0)
		rot+=4;
	while(rot--)
		rotateMatrix();
	FOR(i,1,n)
	{
		FOR(j,1,n)
			cout<<a[i][j];
		cout<<endl;
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
        input(), solve();
        cout<<'\n';
    }
    return 0;
}
