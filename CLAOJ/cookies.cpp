#include <bits/stdc++.h>
using namespace std;

double a[100000], tree[400000],N;

void build(int id, int l, int r)
{
    if (l == r)
    {
        tree[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    tree[id] = min(tree[id * 2], tree[id * 2 + 1]);
}


int getmax(int id, int l, int r, int u, int v)
{
    if (v < l || u > r)
        return 1e9;
    if (u <= l && v >= r)
        return tree[id];
    int mid = (l + r) / 2;
    return min(getmax(id*2,l,mid,u,v),getmax(id*2+1,mid + 1, r,u,v));
}

int main(int argc, char **argv)
{
    cin >> N;
    double k,maxx=0,sum=0;
    vector <int> ans;
    for (int x = 1; x <= N; x++)
        cin >> a[x],sum+=a[x];
    build(1, 1, N);
    for(int x=1;x<N;x++)
    {
        if((sum-a[x]-getmax(1,1,N,x+1,N))/(N-x-1)>=maxx)
        {
            if((sum-a[x]-getmax(1,1,N,x+1,N))/(N-x-1)>maxx)
            {
             
				maxx=(sum-a[x]-getmax(1,1,N,x+1,N))/(N-x-1);
                sum-=a[x];
                ans.clear();
                ans.push_back(x);
                
            }
            else
            {
                ans.push_back(x);
                sum-=a[x];
            }
        }
   		else
            sum-=a[x];

    }
        
   for(int i : ans)
       cout<<i<<' ';
}
