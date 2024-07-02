#include <bits/stdc++.h>
#define FOR(i,k,n) for(int i = k; i <= n; i++)
#define FORR(i,k,n) for(int i = n; i >= k; i--)
#define pb push_back
#define all(x) begin(x),end(x)
using namespace std;

int dg(string n){ return n.size(); }

string a, b, sum, ans; int maxlen, minlen; char c;

void sol(){
    ans = "#";
    ans.pb('#'); ans += a; ans.pb('\n');
    ans.pb(c); ans.pb('#'); ans += b; ans.pb('\n');
    FOR(i,0,maxlen+1) ans.pb('-'); ans.pb('\n');
    FOR(i,0,maxlen-dg(sum)) ans.pb('#');;
    if (dg(sum) <= minlen) ans.pb('#');
    if (dg(sum) > maxlen) ans.pb('#');
    ans += sum;
}

string add(string a, string b){
    string c = "";
    int tmp = 0, s = 0;
    while (a.size() < b.size()) a = '0' + a;
    while (a.size() > b.size()) b = '0' + b;
    FORR(i,0,a.size()-1){
        s = a[i] + b[i] - 96 + tmp;
        tmp = s/10;
        c = (char)(s % 10 + '0') + c;
    }
    return (tmp ? '1' + c : c);
}

string sub(string a, string b){
    string c = "";
    int tmp = 0, s = 0;
    reverse(all(a)); reverse(all(b));
    int n1 = a.size(), n2 = b.size();
    FOR(i,0,n2-1){
        s = a[i] - '0' - (b[i] - '0') - tmp;
        if (s < 0) s += 10, tmp = 1; else tmp = 0;
        c.pb(s+'0');
    }
    FOR(i,n2,n1-1){
        s = a[i] - '0' - tmp;
        if (s < 0) s += 10, tmp = 1; else tmp = 0;
        c.pb(s + '0');
    }
    reverse(all(c));
    while (c[0] == '0') c.erase(c.begin());
    return c;
}

void sol1(){
    ans = "";
    ans.pb('#'); ans = ans + a; ans.pb('\n');
    ans.pb(c); FOR(i, minlen, maxlen-1) ans.pb('#');;
    ans += b; ans.pb('\n');
    FOR(i,0,maxlen) ans.pb('-'); ans.pb('\n');
    FOR(i,0,maxlen-dg(sum)) ans.pb('#');;
    if (dg(sum) < minlen) ans.pb('#');;
    ans += sum;
}

void sol2(){
    ans = "#";
    FOR(i,minlen,maxlen) ans.pb('#'); ans += a; ans.pb('\n');
    ans += c; ans.pb('#'); ans += b; ans.pb('\n');
    FOR(i,0,maxlen+1) ans.pb('-');ans.pb('\n');
    FOR(i,0,maxlen-dg(sum)+1) ans.pb('#');;
    if (dg(sum) <= minlen) ans.pb('#');;
    ans += sum;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> a >> c >> b;
    if (c == '+') sum = add(a,b); else sum = sub(a,b);
    maxlen = max(dg(a), dg(b)), minlen = min(dg(a), dg(b));
    if (dg(a) == dg(b)) sol();
    else if (maxlen == dg(a)) sol1();
    else sol2();
    cout << ans;
}
