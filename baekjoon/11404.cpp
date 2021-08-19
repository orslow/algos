// basic floyd
#include <bits/stdc++.h>

using namespace std;

int so1[101][101];

void floyd(int n) {

    for(int c=1; c<=n; c++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                so1[i][j] = min(so1[i][c] + so1[c][j], so1[i][j]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            so1[i][j]=987654321;
        }
    }

    for(int i=1; i<=n; i++) {
        so1[i][i]=0;
    }

    int a, b, c;
    while(m--) {
        cin >> a >> b >> c;
        so1[a][b] = min(c, so1[a][b]);
    }

    floyd(n);

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(so1[i][j] == 987654321) cout << 0 << ' ';
            else cout << so1[i][j] << ' ';
        }
        cout << '\n';
    }
}
