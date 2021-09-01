// tomato BFS
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

int tom[105][105][105];

int mx[6]={0, 1, 0, -1, 0, 0};
int my[6]={1, 0, -1, 0, 0, 0};
int mz[6]={0, 0, 0, 0, 1, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n, h;
    cin >> m >> n >> h;

    queue <tuple<int, int, int, int>> qu;

    for(int i=0; i<h; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<m; k++) {
                cin >> tom[j][k][i];
                if(tom[j][k][i]==1) {
                    qu.push(make_tuple(j, k, i, 0));
                }
            }
        }
    }

    int x, y, z, cx, cy, cz, d;
    int ans=0;
    while(!qu.empty()) {
        tie(x, y, z, d)=qu.front();qu.pop();
        if(d>ans) ans=d;

        for(int i=0; i<6; i++) {
            cx=x+mx[i]; cy=y+my[i]; cz=z+mz[i];

            if(cx<0 || cx>=n || cy<0 || cy>=m || cz<0 || cz>=h) continue;

            if(tom[cx][cy][cz]==0) {
                tom[cx][cy][cz]=1;
                qu.push(make_tuple(cx, cy, cz, d+1));
            }
        }
    }

    for(int i=0; i<h; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<m; k++) {
                if(tom[j][k][i]==0) {
                    cout << -1 << '\n';
                    return 0;
                }
            }
        }
    }
    cout << ans << '\n';
}

