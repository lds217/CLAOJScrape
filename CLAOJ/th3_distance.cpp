#include <iostream>
#include <cmath>
using namespace std;

struct point
{
    int X,Y;
};

double findM(point Q,point P)
{

    double a = Q.Y - P.Y;
     double b = P.X - Q.X;
    double c = a * (P.X) + b * (P.Y);
    return c/a;
}



int distance(point a, point b, int M)
{
    return sqrt(pow((a.X-M),2)+pow(a.Y,2))+sqrt(pow((b.X-M),2)+pow(b.Y,2));
}

int main()
{
    freopen("DISTANCE.INP","r",stdin);
     freopen("DISTANCE.OUT","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        point a,b;
        cin>>a.X>>a.Y>>b.X>>b.Y;
        if(a.X==b.X)
            cout<<distance(a,b,a.X);
        else
            if(a.Y*b.Y<0)
                cout<<distance(a,b,findM(a,b));
            else
                if(a.Y==0)
                    cout<<distance(a,b,a.X);
                else
                    if(b.Y==0)
                        cout<<distance(a,b,b.X);
                    else
                    {
                        a.Y=-a.Y;
                        cout<<distance(a,b,findM(a,b));
                    }

            cout<<endl;

    }
}
