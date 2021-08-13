#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int so1[1001][1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    if (n==1) {
        cout << 1 << '\n';
        return 0;
    }

    for(int i=1; i<=n; i++) {
        so1[i][0] = 1;
        so1[i][1] = i;
        so1[i][i] = 1;
    }

    for(int i=0; i<n; i++) {
        for(int j=2; j<=i; j++) {
            // cout << so1[i][j] << ' ';
            so1[i][j] = (so1[i-1][j] + so1[i-1][j-1]) % 10007;
        }
    }

    /*
    for(int i=0; i<=n; i++) {
        cout << i << ": ";
        for(int j=0; j<=n; j++) {
            cout << so1[i][j] << ' ';
        }
        cout << '\n';
    }
    */

    cout << (so1[n-1][k] + so1[n-1][k-1]) % 10007 << '\n';

}

