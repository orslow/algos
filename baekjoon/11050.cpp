// easy one
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k, a=1, b=1, c;
    cin >> n >> k;

    c = n-k;

    while(c) {
        b *= c;
        c--;
    }
    while(k) {
        b *= k;
        k--;
    }

    while(n) {
        a *= n;
        n-=1;
    }

    // cout << a << ' ' << b << '\n';
    cout << a / b << '\n';

}

