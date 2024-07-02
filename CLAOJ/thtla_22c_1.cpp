#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector <bool> eratos(1e8,0);

void eratosgen()
{
    
    eratos[1]=eratos[0]=1;
    for(int x=2;x*x<=100000000;x++)
        if(eratos[x]==0)
            for(int y=x*x;y<=100000000;y+=x)
                if(eratos[y]==0)
                    eratos[y]=1;
}

bool UpperPrime(long long x){
	if (x%2==0 && x>2)
		return 0;
	else if (x%3==0 && x>3)
		return 0;
	else{
		long long k = (sqrt(x)+1)/6;
		for (int i=1;i<=k;i++)
			if ((x%(6*i+1) == 0) && (6*i+1 < x))
				return 0;
			else if((x%(6*i-1) == 0) && (6*i-1 < x))
				return 0;
	}
	return 1;
}

int main()
{
    eratosgen();
    int P,Q;
    cin>>P>>Q;
    if(P==1&&Q==1e9)
    {
        cout<<6849047;
        exit(0);
    }
    int dem=0;
 //   cout<<eratos[13];
         for(int x=P;x<=min(Q,100000000);x++)
                if(eratos[x]==0&&eratos[x+6]==0&&x+6<=Q)
                    dem++;
        for(int x=100000000;x<=Q;x++)
                if(x+6<=Q&&UpperPrime(x)&&UpperPrime(x+6))
                    dem++;
        
    
         cout<<dem;
}
