#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    map<int , int> mp;
    cin >> n;
    int a;
    for(int i = 1 ; i <= n ; i++) cin >> a , mp[a]++;
    int res = 0;
    for(auto tmp : mp) res = max(res , tmp . second);
    cout << res;



}
