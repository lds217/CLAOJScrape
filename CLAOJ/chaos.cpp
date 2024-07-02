#include <iostream>

using namespace std;
int main()
{
	long long a,b,c,d,k;
	cin>>a>>b>>c>>d>>k;
	int res=0;
	res=a*b-c;
	for (int i=2;i<=k;i++){	
         res=res*b-c;
		if (res < 0)
        {
            cout<<"0";
			return 0;
        }
		if(res>d)
        {
            cout<<d;
            return 0;
		}
       
    }
	cout<<res;
	return 0;
	
}
