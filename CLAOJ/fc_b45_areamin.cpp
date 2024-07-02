#include <iostream>
#include <iomanip>
#include<cstdio>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        double n,a,b,pi=3.14;
         scanf("%lf%lf%lf",&n,&a, &b);
      // printf("%d", &a);
        double sum=4*(n/(4*a+b*pi));
        printf("%.1f\n", sum);
    }
}
