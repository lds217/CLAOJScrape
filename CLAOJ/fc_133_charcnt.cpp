//MU voi dich
#include <bits/stdc++.h>
using namespace std;

int n,tree[26][500005];
string S;

void upd(int cha, int pos, int val)
{
	while(pos<=n)
	{
		tree[cha][pos]+=val;
		pos+=(pos &-pos);
	}
}

int get(int cha,int r)
{
	int res=0;
	while(r>0)
	{
		res+=tree[cha][r];
		r-=(r &-r);
	}
	return res;
}

int main()
{
	int q,l,r,type;
	cin>>n;
	cin>>S;
	for(int x=0;x<S.size();x++) upd(S[x]-'a',x+1,1);
	cin>>q;
	while(q--)
	{
		cin>>type>>l;
		if(type==1)
		{
			char c;
			cin>>c;
			upd(S[l-1]-'a',l,-1);
			S[l-1]=c;
			upd(c-'a',l,1);
		}
		else
		{
			cin>>r;
			int dem=0;
			for(int i=0;i<26;i++)
				if(get(i,r)-get(i,l-1)>0)
					dem++;
			cout<<dem<<endl;
		}
	}
	
}
