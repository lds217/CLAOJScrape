#include <bits/stdc++.h>

using namespace std;

int num[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
long long tong = 0;

int main() {
    string s;

    cin >> s;

    for (auto i : s) {
        tong += num[i - '0'];
    }

    cout << tong;
}
