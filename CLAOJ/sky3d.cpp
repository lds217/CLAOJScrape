// Created by lds
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i) 
#define FORD(i, a, b) for(int i = (a), _b = (b); i >= _b; --i)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define MASK(i) (1ll<<(i))
#define BIT(t, i) (((t)>>(i))&1)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef pair<int, int> ii;

/***Common Functions***/
template <class T>
bool minimize(T &a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

template <class T>
bool maximize(T &a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

template<class T>
void read(T &a) {
	a = 0;
	char c; 
	while (!isdigit(c = getchar())) {}
	do {
		a = a*10 + (c-'0');
	} while (isdigit(c = getchar()));
}

template<class T> 
void write(T a){
	if (a > 9) write(a/10);
	putchar(a%10 + '0');
}

/***End of Template***/
const int MAX = 5e4+5;
const int N = 5e4+5;
const int S = 5;
int start[MAX], step[MAX];
vi doge[N];
int numDoge, numSky;
int dist[N<<S];
vector<ii> adj[N];
const int INF = 1e9;

void Input() {
	cin >> numSky >> numDoge;
	FOR(i, 0, numDoge-1) {
		cin >> start[i] >> step[i];
		doge[start[i]].pb(i);
	}
}

#define key(node, step) (((node)<<(S))|(step))

void Solve() {
	memset(dist, 0x3f, sizeof dist);
	dist[key(start[0], 0)] = 0;
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.push(mp(0, key(start[0], 0)));
	while (pq.size()) {
		auto [curDist, state] = pq.top(); pq.pop();
		int pos = state>>S, curStep = state&(MASK(S)-1);
		// cout << curDist << ' ' << pos << ' ' << curStep << '\n';
		if (dist[state] != curDist) continue;
		if (pos == start[1]) {
			cout << curDist;
			return;
		}
		if (curStep == 0) { // change doge
			for(int d : doge[pos]) {
				if (step[d] < MASK(S)) {
					if (minimize(dist[key(pos, step[d])], curDist)) pq.push(mp(curDist, key(pos, step[d])));
				} else {
					for(int x = start[d] + step[d], cnt = 1; x < numSky; x += step[d], cnt++) {
						if (minimize(dist[key(x, 0)], curDist + cnt)) pq.push(mp(curDist+cnt, key(x, 0)));
					}
					for(int x = start[d] - step[d], cnt = 1; x >= 0; x -= step[d], cnt++) {
						if (minimize(dist[key(x, 0)], curDist + cnt)) pq.push(mp(curDist+cnt, key(x, 0)));
					}
				}
			}
		} else {
			if (pos-curStep >= 0 && minimize(dist[key(pos-curStep, curStep)], curDist+1)) 
				pq.push(mp(curDist+1, key(pos-curStep, curStep)));
			if (pos+curStep < numSky && minimize(dist[key(pos+curStep, curStep)], curDist+1))
				pq.push(mp(curDist+1, key(pos+curStep, curStep)));
			if (minimize(dist[key(pos, 0)], curDist)) pq.push(mp(curDist, key(pos, 0)));
		}
	}

	cout << -1;
}	

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	#ifdef ONLINE_JUDGE
		freopen("sky.inp", "r", stdin);
		freopen("sky.out", "w", stdout);
	#endif
	// if (fopen("inputf.in", "r")) freopen("inputf.in", "r", stdin);
	Input(), Solve();
	return 0;
}
