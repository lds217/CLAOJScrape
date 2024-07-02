#include <iostream>
using namespace std;
int dem=0,a[100000];

void Try(int i,int Sum,int n)
{  
        for(int x=0;x<=1;x++)
        {
            a[i]=x;
            if(i==n)
            {
                dem++; 
                if(dem==Sum)
                {
                    for(int j=1;j<=n;j++)
                        if(a[j]==1)
                            cout<<7;
                        else
                            cout<<4;
                
                        return;
                }
            }

            else
                Try(i+1,Sum,n);
        }
        
  
    
}

int main()
{
    int Sum;
    cin>>Sum;
    int n=1;
    while(dem<Sum)
    {
    Try(1,Sum,n);
    n++;
    }
    
}
