#include <iostream>
#pragma gcc optimize
using namespace std;

int multiplyTwoNumbers(int a, int b) {
   int result = 0;
   while (b > 0) {
      if (b & 1) {
         result += a;
         }
      a = a << 1;
      b = b >> 1;
   }
   return result;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin>>N;
    if(N==1)
        cout<<0;
    else
    {
        int res=0;
        for(int x=1;x<N;x++){
            if(multiplyTwoNumbers(x,x)<N)
            {
                res++;
                for(int i=x+1;multiplyTwoNumbers(i,x)<N;i++)
                    res+=2;
            }
        }
        cout<<res;
    }
}
