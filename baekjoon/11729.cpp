#include <bits/stdc++.h>

using namespace std;


void hanoi(int n, int a, int b, int c) {
    if (n == 1) {
        cout << a << " " << b << '\n';
    }
    else {
        hanoi(n-1, a, c, b);
        cout << a << " " << b << '\n';
        hanoi(n-1, c, b, a);
    }
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    int n;

    cin >> n;

    cout << int(pow(2, n)) - 1 << '\n'; // pow(2, n) = 1.04858e+06

    hanoi(n, 1, 3, 2);
}

