#include <bits/stdc++.h>
using namespace std;
int main(){

    int n;
	cin>>n; 
	double ans=0;
	while(n--)
	{
		double a,b;
		cin>>a>>b;
		ans+=a*b;
	}
	cout<<setprecision(3)<<fixed<<ans;
    return 0;

}
