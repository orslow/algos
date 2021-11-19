#include <bits/stdc++.h>

using namespace std;

int so1[2][101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    for(int i=0; i<2; i++) {
        for(int j=0; j<n; j++) {
            cin >> so1[i][j];
        }
    }

    sort(so1[0], so1[0]+n);
    sort(so1[1], so1[1]+n);

    int l=0, r=n-1;
    while(k--) {

        int c=max(so1[0][0]*so1[1][l], max(so1[0][0]*so1[1][r], max(so1[0][n-1]*so1[1][r], so1[0][n-1]*so1[1][l])));

        if(c==so1[0][0]*so1[1][l] || c==so1[0][n-1]*so1[1][l]) l++;
        else r--;
    }

cout << max(so1[0][0]*so1[1][l], max(so1[0][0]*so1[1][r], max(so1[0][n-1]*so1[1][r], so1[0][n-1]*so1[1][l])));
}
