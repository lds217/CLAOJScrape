#include <iostream>
using namespace std;

int main()
{
int n;int j;int k;
cin>>n;
int count=n;
j=n*2-1; //biet duoc cai canh day' dai bnhiu
int temp=n;
for(int i=0;i<n;i++)
{   for(k=0;k<=n;k++)
        { cout<<" ";
        if(k==temp)
            {for(int t=temp;t<=count;t++)
                cout<<"*";}
        }
    temp--;
    count++;
    cout<<endl;
}
system("pause");
return(0);
}
