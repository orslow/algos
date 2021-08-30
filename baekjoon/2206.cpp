// BFS can break wall
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

int boq[1001][1001];

bool vis[1001][1001][2];

int mx[4]={-1, 0, 1, 0};
int my[4]={0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    string ts;
    for(int i=1; i<=n; i++) {
        cin >> ts;
        for(int j=0; j<m; j++) {
            boq[i][j+1]=ts[j] - '0';
        }
    }

    /*
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cout << boq[i][j] << ' ';
        }
        cout << '\n';
    }
    */

    queue <tuple<int, int, int, int>> qu;
    qu.push(make_tuple(1, 1, 1, 0));
    vis[1][1][1]=1;

    int tx, ty, power, w, cx, cy;
    while(!qu.empty()) {
        tie(cx, cy, power, w)=qu.front(); qu.pop();

        // cout << cx << ' ' << cy << ' ' << power << ' ' << w <<'\n';

        if(cx==n && cy==m) {
            cout << w+1 << '\n';
            return 0;
        }

        for(int i=0; i<4; i++) {
            tx=cx+mx[i]; ty=cy+my[i];

            if(tx>=1 && tx<=n && ty>=1 && ty<=m) {
                if(boq[tx][ty]==0 && vis[tx][ty][power]==0) {
                    vis[tx][ty][power]=1;
                    qu.push(make_tuple(tx, ty, power, w+1));
                }
                if(boq[tx][ty]==1 && power==1 && vis[tx][ty][0]==0) {
                    vis[tx][ty][0]=1;
                    qu.push(make_tuple(tx, ty, 0, w+1));
                }
            }

        }
    }

    cout << -1 << '\n';
}


