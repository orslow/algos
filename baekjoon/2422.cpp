// easy but hard for me
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

bool so1[201][201];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, a, b;
    cin >> n >> m;

    for(int i=0; i<m; i++) {
        cin >> a >> b;
        so1[a][b]=true;
        so1[b][a]=true;
    }

    int ans=0;
    for(int i=1; i<=n; i++) {
        for(int j=i+1; j<=n; j++) {
            if(!so1[i][j]) {
                for(int k=j+1; k<=n; k++) {
                    if(!so1[i][k] && !so1[j][k]) ans++;
                }
            }
        }
    }

    cout << ans << '\n';

}

