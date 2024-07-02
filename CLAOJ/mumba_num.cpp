#include <iostream>
#include <bits/stdc++.h>
#define in freopen
#define ll long long
#define task "MUMBA"
#define ed "\n"

using namespace std;
bool checka(string t){
    if(t.size()<3)return true;
    ll n = t.size()-1;
    if(t[n] == 'a' && t[n-1]=='a' && t[n-2]=='a')return false;
    return true;
}
bool checkb(string t){
    if(t.size()<2)return true;
    ll n = t.size()-1;
    if(t[n]=='b' && t[n-1]=='b')return false;
    return true;
}
bool check(string t){
    if(t.size()<6)return true;
    ll n = t.size()-1;
    if(t[n]==t[n-2] && t[n-4]==t[n] && t[n-1]==t[n-3] && t[n-1]==t[n-5])return false;
    if(t.size()>8){
        if(t[n]==t[n-3] && t[n]==t[n-6] && t[n-1]==t[n-4] && t[n-1]==t[n-7] && t[n-2]==t[n-5] && t[n-2]==t[n-8])return false;
    }
    if(t.size()>14){
        if(t[n]==t[n-5] && t[n]==t[n-10] && t[n-1]==t[n-6] && t[n-1]==t[n-11] && t[n-2]==t[n-12] && t[n-2]==t[n-7] && t[n-3]==t[n-8] && t[n-3]==t[n-13] &&t[n-4]==t[n-9] && t[n-4]==t[n-14])return false;
    }
    return true;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    in(task".inp","r",stdin);
    in(task".out","w",stdout);
    ll k;
    cin>>k;
    set<string> q,p;
    q.insert("a");
    q.insert("b");
    string t;
    for(int i = 2; i<=k; i++){
        for(auto it = q.begin(); it!=q.end(); it++){
            //cout<<t<<ed;
            t = *it;
            if(checka(t + 'a') && check(t + 'a')){
                //cout<<t<<ed;
                //cout<<t + 'a'<<ed;
                p.insert(t + 'a');
            }
            if(checkb(t + 'b') && check(t + 'b')){
                //cout<<t<<ed;
                p.insert(t + 'b');
            }
            //q.erase(it);
        }
        q = p;
        p.clear();
        if(q.size()==0)break;
    }
    //for(auto it = q.begin(); it!=q.end(); it++)
        //cout<<*it<<ed;
    cout<<q.size();
    return 0;
}
