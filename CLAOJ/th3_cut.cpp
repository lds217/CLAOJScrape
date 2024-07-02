#include <iostream>
#include <cmath>
#include <set>
using namespace std;

struct point{
    int X,Y;
};

int x_inter(point Q,point P,int x)
{

    double a = Q.Y - P.Y;
    double b = P.X - Q.X;
    double c = a * (P.X) + b * (P.Y);
    return (-a*x+c)/b;
}
int y_inter(point Q,point P,int y)
{

    double a = Q.Y - P.Y;
    double b = P.X - Q.X;
    double c = a * (P.X) + b * (P.Y);
    //ax+by=c
    return (c-b*y)/a;
}

int main()
{
    freopen("CUT.INP","r",stdin);
    freopen("CUT.OUT","w",stdout);
    set <pair<int,int> > ans,ans1;
    int N,M,K;
    cin>>M>>N>>K;
        point a,b;
        a.X=1;a.Y=1;
        b.X=M+1;
        b.Y=N+1;
        for(int x=1;x<=M;x++)
            ans.insert(make_pair(x,x_inter(a,b,x)));
        for(int y=2;y<=N;y++)
             ans.insert(make_pair(y_inter(a,b,y),y));
    if(K==2)
    {
        for(auto i: ans)
        {
            int x=i.first;
            int y=i.second;
                ans1.insert(make_pair(x,N-y+1));
                ans1.insert(make_pair(M-x+1,y));
        }
         cout<<ans1.size()<<endl;
        for(auto i: ans1)
            cout<<'('<<i.first<<','<<i.second<<") ";
    }
    else
    {
        cout<<ans.size()<<endl;
        for(auto i: ans)
            cout<<'('<<i.first<<','<<i.second<<") ";
    }
}
