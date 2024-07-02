#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool upperPrime(long long x){
    if(x==0||x==1) return false;
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
int main() {
    long long N;
    cin>>N;
   
       if(upperPrime(N)==0)
       {
           cout<<"khong";
           return 0;
       }
    
   
    cout<<"sieu nguyen to";
}
