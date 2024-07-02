#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define fi first
#define se second

int n, m, p, maxx = -1;
vector<pair<int, int>> K;

int process(int d) {
    int stop = 1;
    int time = d;
    int people = 0;
    for (int x = 0; x < n; x++) {
         if(K[x].fi > p) break;
         int add = K[x].fi - stop;
         time += add;
         stop = K[x].fi;
         if(K[x].se <= time) people ++;
    }
    return people >= m;
}

signed main(int argc, char **argv) {

    cin >> n >> m >> p;

    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        K.push_back({u, v});
        maxx = max(maxx, v);
    }
    sort(K.begin(), K.end());
    int low = 1, high = maxx;
    int minn = 1e9;
    while (low <= high) {
        int mid = (low + high) / 2;
        if(process(mid)){
            minn = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    cout << minn;
}
