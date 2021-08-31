// dijkstra (full explore)
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

int items[105];

vector <pair<int, int>> roads[105];

int trp[105][105];

const int INF=987654323;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, r, a, b, l;

    cin >> n >> m >> r;
    for(int i=1; i<=n; i++) {
        cin >> items[i];
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            trp[i][j]=INF;
        }
        trp[i][i]=0;
    }

    for(int i=0; i<r; i++) {
        cin >> a >> b >> l;
        trp[a][b]=l;
        trp[b][a]=l;
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            for(int k=1; k<=n; k++) {
                trp[j][k] = min(trp[j][k], trp[j][i]+trp[i][k]);
            }
        }
    }

    int tmp, ans=0;
    for(int i=1; i<=n; i++) {
        tmp=0;
        for(int j=1; j<=n; j++) {
            if(trp[i][j]<=m) {
                tmp+=items[j];
            }
        }
        if(tmp>ans) ans=tmp;
    }

    cout << ans << '\n';

}
