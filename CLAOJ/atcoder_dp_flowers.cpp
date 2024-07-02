#include <bits/stdc++.h>
using namespace std;

#define int long long

int tree[800004],n,h1[800004];

int getmax(int id, int l, int r, int u, int v)
{
    if (v < l || u > r)
        return 0;
    if (u <= l && v >= r)
        return tree[id];
    int mid = (l + r) / 2;
    return max(getmax(id*2,l,mid,u,v),getmax(id*2+1,mid + 1, r,u,v));
}

void update(int id, int l, int r, int pos, int val)
{
    if (pos < l || pos>r)
        return;
    if (l == r)
    {
        tree[id] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(id * 2, l, mid, pos, val);
    update(id * 2 + 1, mid + 1, r, pos, val);
    tree[id] = max(tree[id * 2], tree[id * 2 + 1]);
}


signed main()
{
	int h[400004],a[400004];
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>h[i];
    for(int i=1;i<=n;i++)	cin>>a[i];
    for(int i=1;i<=n;i++)
         update(1,1,n,h[i],getmax(1,1,n,1,h[i]-1)+a[i]);
    cout<<getmax(1,1,n,1,n);
}
