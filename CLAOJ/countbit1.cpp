#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll binary(ll x){
    ll dem=0;
    while(x>0){
        ll tmp=x%2;
        x/=2;
        if (tmp==1) dem++;
        
    }
    return dem;
    
}

int main(){
    ll n;
    ll a[10000008], b[10000008];
    cin>>n;
    for (ll i=0; i<n; i++) cin>>a[i];
    sort (a, a+n, greater<ll>());
    for(ll i=0; i<n; i++){
       // cout<<binary(a[i])<<" ";
       b[i]=binary(a[i]);
    }
    ll max=b[0], vitri=0;
    for(ll i=0; i<n; i++){
        if (b[i]>max){
            max=b[i];
            vitri=i;
        } 
    }
    cout<<a[vitri];
    
}
