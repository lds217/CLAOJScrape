#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool Upperprime(long long a)
{
    if(a==1||a==0)
        return 0;
    if(a%2==0&&a>2)
        return 0;
    else if(a%3==0&&a>3)
        return 0;
    else
    {
        long long k=(sqrt(a)+1)/6;
        for(int i=1;i<=k;i++)
        {
            if(a%(6*i+1)==0&&6*i+1<=a)
                return 0;
            else
                if(a%(6*i-1)==0&&6*i-1<=a)
                    return 0;
        }
        return 1;
    }
    
}

int main()
{
    int dup[100000]={0};
    string str;
    cin>>str;
    for(int x=0;x<str.size();x++)
        if(Upperprime(str[x]-'0'))
            if(dup[str[x]-'0']<1)
            {
                cout<<str[x]<<" ";
                dup[str[x]-'0']++;
            }
}
