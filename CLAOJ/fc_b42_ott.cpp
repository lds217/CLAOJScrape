#include <iostream>
using namespace std;

int main()
{
    char a, b;
    cin >> a >> b;
    if (a == b)
        cout << "D";
    else if (a == 'S' && b == 'P' || a == 'R' && b == 'S' || a == 'P' && b == 'R')
        cout << "A";
    else
        cout << "B";
}
