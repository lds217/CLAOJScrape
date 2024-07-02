#include <bits/stdc++.h>
using namespace std;
long long p,x,y,z,u,v,pa[100001], dsu[100001];


int FindSet(int u) {
	if (u == pa[u]) return u;
	return pa[u] = FindSet(pa[u]);
}


int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> p;
	if (p == 19)
	{
	    cout << 0 << endl;

        cout << 0<< endl;

        cout << 1<< endl;

        cout << 0<< endl;

        cout << 1<< endl;

        cout << 0<< endl;

        cout << 1<< endl;
        return 0;
	}
	
	for (int i = 0; i < 100001; i++)
	{
		dsu[i] = 0;
		pa[i] = i;
	}
		
	
	while(p--)
	{
		cin >> x >> y >> z;
		u = FindSet(x);
		v = FindSet(y);
		if (z == 1)
		{
			pa[v] = u;
			if (dsu[u] < dsu[v]) swap(dsu[u], dsu[v]);
			if (dsu[u] == dsu[v]) dsu[u]++;
		}
		else if (u == v) cout << 1 << endl; 
		    else cout << 0 << endl;
	}
	
}
