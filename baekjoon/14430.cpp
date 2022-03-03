// basic dp
#include <bits/stdc++.h>

using namespace std;

int so1[303][303];
int so2[303][303];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;

    for(int i=1; i<=n; i++) {
      for(int j=1; j<=m; j++) {
        cin >> so1[i][j];
      }
    }

    for(int i=1; i<=n; i++) {
      for(int j=1; j<=m; j++) {
        so2[i][j]=max(so2[i-1][j], so2[i][j-1])+so1[i][j];
      }
    }

    cout << so2[n][m];
}
