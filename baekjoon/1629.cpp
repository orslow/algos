#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll rc(int a, int b, int c) {

    if (b == 1) return a % c;

    if (b%2 == 0) {
        ll r = rc(a, b/2, c);
        return (r * r) % c;
    } else {
        return (a * rc(a, b-1, c)) % c;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;

    cin >> a >> b >> c;

    cout << rc(a, b, c) << '\n';

}


