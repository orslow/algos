#include <bits/stdc++.h>

using namespace std;


int z(int n, int r, int c) {
    if (n == 0)
        return 0;

    if(r < pow(2, n-1) && c < pow(2, n-1)) return z(n-1, r, c);
    if(r < pow(2, n-1) && c >= pow(2, n-1)) return pow(2, n-1)*pow(2, n-1) + z(n-1, r, c-pow(2, n-1));
    if(r >= pow(2, n-1) && c < pow(2, n-1)) return pow(2, n-1)*pow(2, n-1)*2 + z(n-1, r-pow(2, n-1), c);
    return pow(2, n-1)*pow(2, n-1)*3 + z(n-1, r-pow(2, n-1), c-pow(2, n-1));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, r, c;

    cin >> n >> r >> c;

    cout << z(n, r, c) << '\n';
}

