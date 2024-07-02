#include <bits/stdc++.h>
#define FOR(i,k,n) for(int i = k; i <= n; i++)
#define FORR(i,k,n) for(int i = n; i >= k; i--)
#define pb push_back
#define all(x) begin(x),end(x)
#define fi first
#define se second
#define BIT(S, i) (((S)>>(i))&1)
#define MASK(i) ((1ll)<<(i))
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef long double ld;

template<class T> 
    bool maximize(T &a, T b) {
    if (a < b) {a = b; return true;}
    return false;
}

template<class T>
    bool minimize(T &a, T b) {
    if (a > b) {a = b; return true;}
    return false;
}

int n, k; string x, s;

void sol1(){
    stack<char> st;
    FOR(i,0,n-1){
        while (st.size() && x[i] > st.top() && k) st.pop(), --k;
        st.push(x[i]);
    }
    while (k--) st.pop();
    while (st.size()) s += st.top(), st.pop();
}

void sol2(){
    stack<char> st;
    FOR(i,0,n-1){
        while (st.size() && x[i] < st.top() && k) st.pop(), --k;
        st.push(x[i]);
    }
    while (k--) st.pop();
    while (st.size()) s += st.top(), st.pop();
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); 
    int t; cin >> t;
    cin >> n >> k >> x;
    if (!k) return cout << x, 0;
    if (t == 1) sol1(); else sol2();
    reverse(all(s));
    int pos = 0;
    while (s[pos] == '0') pos++;
    if (pos == s.size()) return cout << 0, 0;
    FOR(i,pos,s.size()-1) cout << s[i];
}
