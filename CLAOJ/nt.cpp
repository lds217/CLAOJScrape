#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool Prime(long long x){
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
    int K;
    cin>>K;
    unsigned long long i=1;
    int cnt=0;
    int temp=0; 
    string B="";
    int check=0;
    while(cnt!=K)
    {
        i++;
        if(Prime(i))
        {
            if(check==1)
            {   
                B=to_string(temp)+to_string(i);
                if(Prime(stoll(B)))
                    cnt++;
                check=0;
            }
            else
            {
                temp=i;
                check++;
            }   
        } 
    }
    cout<<stoll(B);

}
