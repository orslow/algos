// rest
#include <bits/stdc++.h>

using namespace std;

int so1[303][303];

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

    int k;
    cin >> k;

    int x1,y1,x2,y2;
    while(k--) {
      cin >> x1 >> y1 >> x2 >> y2;

      int ans=0;
      for(int i=x1; i<=x2; i++) {
        for(int j=y1; j<=y2; j++) {
          ans+=so1[i][j];
        }
      }

      cout << ans << '\n';
    }
}
