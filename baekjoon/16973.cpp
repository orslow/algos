// little difference makes answer
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

int so1[1003][1003];
bool vis[1003][1003];

int mx[4]={1, 0, -1, 0};
int my[4]={0, -1, 0, 1};

vector <pair<int, int>> dis;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin >> so1[i][j];
            if(so1[i][j]==1) {
                dis.push_back({i, j});
            }
        }
    }

    int h, w, sx, sy, fx, fy, cx, cy, tx, ty, step;
    cin >> h >> w >> sx >> sy >> fx >> fy;

    /*
    int x, y;
    for(auto v: dis) {
        x=v.first;y=v.second;
        for(int i=x-h+1; i<=x; i++) {
            for(int j=y; j>=y-w+1; j--) {
                if(i>=1 && j>=1 && i<=n && j<=m) vis[i][j]=1;
            }
        }

        for(int i=x; i>=x-h+1; i--) {
            for(int j=y; j<=y+w-1; j++) {
                if(i>=1 && j>=1 && i<=n && j<=m) vis[i][j]=1;
            }
        }

        for(int i=x; i<=x+h-1; i++) {
            for(int j=y; j<=y+w-1; j++) {
                if(i>=1 && j>=1 && i<=n && j<=m) vis[i][j]=1;
            }
        }

        for(int i=x; i<=x+h-1; i++) {
            for(int j=y; j>=y-w+1; j--) {
                if(i>=1 && j>=1 && i<=n && j<=m) vis[i][j]=1;
            }
        }

    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cout << vis[i][j] << ' ';
        }
        cout << '\n';
    }
    */

    queue <tuple<int, int, int>> qu;
    qu.push(make_tuple(sx, sy, 0));
    vis[sx][sy]=1;

    tuple<int, int, int> tmp;
    while(!qu.empty()) {
        tie(tx, ty, step)=qu.front();qu.pop();

        if(tx==fx && ty==fy) {
            cout << step;
            return 0;
        }

        for(int i=0; i<4; i++) {
            cx=tx+mx[i]; cy=ty+my[i];

            if(cx>=1 && cy>=1 && cx+h-1<=n && cy+w-1<=m && vis[cx][cy]==0) {
                vis[cx][cy]=1;
                bool avail=true;
                if(i==0) {
                    for(int u=cy; u<=cy+w-1; u++) {
                        if(so1[cx+h-1][u]==1) {
                            avail=false;
                            break;
                        }
                    }
                } else if(i==1) {
                    for(int u=cx; u<=cx+h-1; u++) {
                        if(so1[u][cy]==1) {
                            avail=false;
                            break;
                        }
                    }
                } else if(i==2) {
                    for(int u=cy; u<=cy+w-1; u++) {
                        if(so1[cx][u]==1) {
                            avail=false;
                            break;
                        }
                    }
                } else {
                    for(int u=cx; u<=cx+h-1; u++) {
                        if(so1[u][cy+w-1]==1) {
                            avail=false;
                            break;
                        }
                    }
                }
                if(avail) {
                    qu.push(make_tuple(cx, cy, step+1));
                }
            }
        }
    }
    cout << -1;
}
