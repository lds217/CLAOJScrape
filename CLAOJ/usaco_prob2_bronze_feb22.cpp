#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll n,A[100010],B[100010],posofA[100010],changed[100010]={0};
    cin>>n;
    for(int i=0;i<n;i++) cin>>A[i],posofA[A[i]]=i;
    for(int i=0;i<n;i++) cin>>B[i];
    ll step=0,res=0;
    for(int i=0;i<n;i++) 
    {
        while(changed[step]==true) step++;
        if(B[i]==A[step])
            step++;
        else
        {
            changed[posofA[B[i]]]=true;
            res++;
        }
    }
    cout<<res;
}
