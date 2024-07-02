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

int idx=1;
map <string,int> k;
string key[10001];
string str;
 ll n=1;
void input()
{
	//cin.ignore();
	getline(cin,str);
}

void lds_go_goooo()
{
	if(str=="")
		return;
	string tmp="";
//	cout<<str[0]<<endl;;
	for(int i=0;i<str.size();i++)	
		if(str[i]>='0'&&str[i]<='9')
			tmp+=str[i];
//	cout<<tmp<<endl;
	int num=stoi(tmp);
//	cout<<num;
	key[idx++]=to_string(num);
	
	k[key[idx-1]]++;
	//cout<<idx-1<<" "<<key[idx-1]<<" "<<	k[key[idx-1]]<<endl;
}

int main()
{

    //freopen(task".INP", "r", stdin);
    //freopen(task".OUT", "w", stdout);
    cin>>n;
    int m=n;
    n++;
    while(n--)
    {
    	
        input(), lds_go_goooo();
    }

    set <int> ans;
    FOR(i,1,m)
    	if(k[key[i]]<=5)
    		ans.insert(stoi(key[i]));

    cout<<ans.size()<<endl;
    for(int s: ans)
    	cout<<s<<endl;
    return 0;
}
