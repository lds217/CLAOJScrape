#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b, c, d;
    while (cin >> a >> b >> c >> d)
    {
        if (a == 0 && b == 0 && c == 0 && d == 0)
            break;
        else
        {
            int p1 = max(a, b) * 10 + min(a, b), p2 = max(c, d) * 10 + min(c, d);

            if (a == b && c != d)
                if(p2==21)
                    cout << "Player 2 wins." << endl;
                else
                    cout << "Player 1 wins." << endl;
            else 
                if (a != b && c == d)
                    if(p1==21)
                        cout << "Player 1 wins." << endl;
                    else
                        cout << "Player 2 wins." << endl;
                else 
                    if (p1 == 21 && p2 != 21)
                        cout << "Player 1 wins." << endl;
                    else 
                        if (p1 != 21 && p2 == 21)
                            cout << "Player 2 wins." << endl;
                        else
                            if (p1 == p2)
                                cout << "Tie." << endl;
                            else 
                                if (p1 > p2)
                                    cout << "Player 1 wins." << endl;
                                else
                                    cout << "Player 2 wins." << endl;
        }
    }
    return 0;
}
