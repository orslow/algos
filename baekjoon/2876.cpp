// silver dp
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

int desk[100005][6];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b;
    cin >> n;

    int ans=0, idx;
    for(int i=1; i<=n; i++) {
        cin >> a >> b;

        desk[i][a]=desk[i-1][a]+1;
        desk[i][b]=desk[i-1][b]+1;

        if(desk[i][a]>ans) {
            ans=desk[i][a];
            idx=a;
        }
        else if(desk[i][a]==ans && idx>a) {
            idx=a;
        }

        if(desk[i][b]>ans) {
            ans=desk[i][b];
            idx=b;
        }
        else if(desk[i][b]==ans && idx>b) {
            idx=b;
        }

        for(int j=1; j<=5; j++) {
            if(j==a || j==b) continue;
            desk[i][j]=0;
        }
    }

    /*
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=5; j++) {
            cout << desk[i][j] << ' ';
        }
        cout << '\n';
    }
    */

    cout << ans << ' ' << idx;
}

