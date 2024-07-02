#include <bits/stdc++.h>
using namespace std;

#define A first
#define B second
#define int double
#define double long double
vector<pair<double, double>> X,Y;
set<pair<double, double>> s;
int m, n, q;

double roundoff(double value, unsigned char prec)
{
  double pow_10 = pow(10.0f, (double)prec);
  return round(value * pow_10) / pow_10;
}


pair<double, double> lineLineIntersection(pair<double, double> A, pair<double, double> B, pair<double, double> C, pair<double, double> D)
{
    double a1 = B.second - A.second;
    double b1 = A.first - B.first;
    double c1 = a1*(A.first) + b1*(A.second);
 
    double a2 = D.second - C.second;
    double b2 = C.first - D.first;
    double c2 = a2*(C.first)+ b2*(C.second);
 
    double determinant = a1*b2 - a2*b1;
 
    if (determinant == 0)
    {
        return make_pair(FLT_MAX, FLT_MAX);
    }
    else
    {
        double x = (b2*c1 - b1*c2)/determinant;
        double y = (a1*c2 - a2*c1)/determinant;
        return make_pair(x, y);
    }
}

signed main()
{
    freopen("CAT.INP","r",stdin);
    freopen("CAT.OUT","w",stdout);   
    cin >> m >> n >> q;
    for (int i = 0; i < q; i++)
    {
        double x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        X.push_back({x1,y1});
        Y.push_back({x2,y2});
    }
    //    for(int x=0;x<q;x++)
    //        cout<<"y="<<(double)PT[x].A<<"x+"<<PT[x].B<<endl;
    int sum = 1;
    map<pair<double, double>, int> K;
    for (int x = 0; x < q; x++)
    {
        int concurrent = 0;
        map<pair<double, double>, int> K;
        for (int i = x - 1; i >= 0; i--)
        {
            // tim giao diem
            double u = roundoff(lineLineIntersection(X[x], Y[x], X[i], Y[i]).A,6);
            double v = roundoff(lineLineIntersection(X[x], Y[x], X[i], Y[i]).B,6);
            if(u!=FLT_MAX&&v!=FLT_MAX)
            {
                if (u > 0 && u < m && v > 0 && v < n && K[{u, v}] == 0)
                {
                    sum++;
                    K[{u, v}]++;
                }
            }
        }
        sum++;
    }
    cout << sum;
}
