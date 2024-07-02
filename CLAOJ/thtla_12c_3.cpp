#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ed << "\n";
#define el cout<<'\n';
#define rep(i,a,n,b) for(int i=a;i<=n;i+=b)
#define foru(i,a,n,b) for(int i=a;i<=n;i+=b)
#define ALL(s) s.begin(),s.end()
#define fi first
#define se second
#define task "BAI3"
#define mem(dp,a) memset(dp,a,sizeof dp)
#define ford(i,a,n,b) for(int i=a; i>=n; i-=b)
#define pb(x) push_back(x);
#define SQ(a) (a)*(a)
#define A(a) abs(a)
#define SZ(a) int(a.size())


const ll mod = 1e9+9;
const ll modul = 998244353;
const int base = 31;

ll get_num(string s){
    ll num = 0;
    for(char c : s){
        num = num * 10 + (c-'0');
    }
    return num;
}

string to_string (ll num){
    string ans = "";
    while(num > 0){
        ans += char((num % 10) + '0');
        num /= 10;
    }
    return ans;
}

int Al(char c){
    return c - 'a' + 1;
}

int NU(char c){
    return (c - '0') % 2;
}

bool maximize(string &x,string y){
    if(x.size() > y.size()) return 1;
    if(y.size() > x.size()) {x = y; return 0;}
    if(x >= y)
        return 1;
    x = y;
    return 0;
}
bool minimize(string &x, string y) {
    if(x.size() < y.size()) return 1;
    if(y.size() < x.size()) {x = y; return 0;}
    if(x <= y)
        return 1;
    x = y;
    return 0;
}

int n,m;
string dp[1000002];
vector <int> a;

void sol()
{
    cin >> n >> m ;
    queue <int> q;int x;
    for(int i=1; i<=n; i++){
        cin >> x; int r = x % m;
        if(dp[r] == "")
            dp[r] = char(x + '0'), a.push_back(x % m) , q.push(r);
    }
    while(q.size()){
        int r = q.front();
        q.pop();
        if(dp[0] != ""){
            cout << dp[0];
            return ;
        }
        for(int i=0; i<n; i++){
            int rn = (r * 10 + a[i]) % m;
            if(dp[rn] == ""){
                dp[rn] = dp[r] + dp[a[i]];
                q.push(rn);
            }
        }
    }
    cout << (dp[0] == "" ? "vo nghiem" : dp[0]);
}

inline void file()
{
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
}

void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

signed main()
{
    fast();
    file();
    int t = 1; //cin >> t;
    while(t --) sol();
    return 0;
}
