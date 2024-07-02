#include <bits/stdc++.h>
#define FOR(i,k,n) for(int i = k; i <= n; i++)
#define int long long
using namespace std;

const int MT = 27022007;

struct Matrix{
    int val[3][3];
    Matrix(){
        memset(val,0,sizeof val);
    }
    Matrix operator * (Matrix b){
        Matrix c;
        FOR(i,1,2) FOR(j,1,2) FOR(k,1,2) c.val[i][j] += val[i][k] * b.val[k][j], c.val[i][j] %= MT;
        return c;
    }
    Matrix Pow(int n){
        if (n == 1) return *this;
        Matrix tmp = Pow(n >> 1);
        tmp = tmp*tmp;
        if (n % 2) tmp = tmp * *this;
        return tmp;
    }
};

void solve(){
    int k, n; cin >> k >> n;
    n = (!k) ? (n*3 + 1) /2 -1 : n*3 ;
    Matrix pnlp;
    pnlp.val[1][1] = pnlp.val[1][2] = pnlp.val[2][1] = 1;
    if(n==1)
    {
    	cout << pnlp.val[1][1]<< '\n';
    	return ;
    }
    pnlp = pnlp.Pow(n-1);
    cout << pnlp.val[1][1] << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t=1; cin >> t;
    while (t--) solve();
}
//flex
