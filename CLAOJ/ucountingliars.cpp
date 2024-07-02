#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<pair<int,char>> K;

   for(int x=0;x<N;x++)
    {
        char a;
        int b;
        cin >> a >> b;
        K.push_back(pair<int,char>(b,a));
    }
    int fi=1e9;
    sort(K.begin(),K.end());
    for(int x=0;x<N;x++)
    {
        int res=0;
        for(int y=0;y<x;y++)
            if(K[y].second=='L')
                res++;
        for(int y=x+1;y<N;y++)
            if(K[y].second=='G')
                res++;
        fi=min(res,fi);
    }
    cout<<fi;
}
