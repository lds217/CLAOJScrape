#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[25],tong[5],ans=1e18,so;
vector <int> kq[5],vec[5];
bool gia;
void cry(int dem) {
    if (dem==n+1) {
        so=max({tong[0],tong[1],tong[2]})-min({tong[0],tong[1],tong[2]});
        if (so<ans) {
            ans=so;
            kq[2]=vec[2];
            kq[1]=vec[1];
            kq[0]=vec[0];
        }
        if (ans==0) gia=true;
        return;
    }
    for (int i=0;i<=2;++i) {
        if (!i){
            vec[i].push_back(dem);
            tong[i]+=a[dem];
            cry(dem+1);
            if (gia) return;
            tong[i]-=a[dem];
            vec[i].pop_back();
        } else{
            if (vec[i-1].back() < dem && vec[i-1].size()){
                vec[i].push_back(dem);
            tong[i]+=a[dem];
            cry(dem+1);
            if (gia) return;
            tong[i]-=a[dem];
            vec[i].pop_back();
            }
        }
    }
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i=1;i<=n;++i) cin >> a[i];
    cry(1);
    if (ans) cout << ans << '\n';
    else cout << "Yes" << '\n';
    for (int i=0;i<=2;++i) {
        for (int j=0;j<kq[i].size();++j) cout << a[kq[i][j]] << " ";
        cout << '\n';
    }
}
