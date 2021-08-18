// 내가 푼 방식 / 찾은 방식
#include <bits/stdc++.h>

using namespace std;

int so1[1025][1025];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, s, cum;
    cin >> n >> m;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> s;
            so1[i][j] = so1[i][j-1] + so1[i-1][j] - so1[i-1][j-1] + s;
        }
    }

    /*
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cout << so1[i][j] << ' ';
        }
        cout << '\n';
    }
    */

    int x1, x2, y1, y2;

    while(m--) {
        cin >> x1 >> y1 >> x2 >> y2;

        cout << so1[x2][y2] - so1[x2][y1-1] - so1[x1-1][y2] + so1[x1-1][y1-1] << '\n';

        /*
        ans=0;
        for(int i=x1-1; i<x2; i++) {
            ans+= (so1[i][y2] - so1[i][y1-1]);
        }
        cout << ans << '\n';
        */

    }
}

