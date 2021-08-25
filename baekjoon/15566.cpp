// still hard to write logic
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

int n, m;

int so1[18][6];
int pl[18][4];

int rot[16][16];

int vis[16];
int ans[16];
bool made[16];

bool done=false;

void valid() {
    bool ok=true;
    for(int i=1; i<=n; i++) {
        for(int j=i+1; j<=n; j++) {
            if(rot[i][j]!=0) {
                int c1=vis[i];
                int c2=vis[j];

                int chi=rot[i][j];

                if(so1[c1][chi] == so1[c2][chi]) continue;
                else {
                    ok=false;
                    break;
                }
            }
        }
    }
    if(ok) {
        done=true;
        for(int i=1; i<=n; i++) {
            ans[i] = vis[i];
        }
    }
}

void bbt(int w) {

    // w: 몇번째 개구리 배치하는 중인지
    if(w==n+1) {
        valid();
    }

    // 개구리가 원하는 곳 방문
    int han=2;
    if(pl[w][1] == pl[w][2]) han=1;
    for(int i=1; i<=han; i++) {
        int du=pl[w][i]; // 현재 방문한 곳
        if(vis[du] == 0) {
            vis[du]=w;
            bbt(w+1);
            vis[du]=0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i=1; i<=n; i++) {
        cin >> so1[i][1] >> so1[i][2] >> so1[i][3] >> so1[i][4];
    }

    for(int i=1; i<=n; i++) {
        cin >> pl[i][1] >> pl[i][2];
    }

    int a, b, t;
    for(int i=0; i<m; i++) {
        cin >> a >> b >> t;
        rot[a][b]=t;
        rot[b][a]=t;
    }

    bbt(1);

    if(!done) cout << "NO" << '\n';
    else {
        cout << "YES" << '\n';
        for(int i=1; i<=n; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
}

