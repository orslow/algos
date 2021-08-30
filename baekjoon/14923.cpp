// no weight minimum distance = BFS
// dirty code
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

int miro[1001][1001];

bool vis1[1001][1001];
bool vis2[1001][1001];

int n, m, hx, hy, ex, ey;

/*
int min_walk=987654321;


void esc(int cx, int cy, int w, bool power) {
    if(cx==ex && cy==ey) {
        if(min_walk>w) min_walk=w;
        return;
    }

    if(cx-1 >= 0 && vis[cx-1][cy]==0) {
        if(miro[cx-1][cy]==0) {
            vis[cx-1][cy]=1;
            esc(cx-1, cy, w+1, power);
            vis[cx-1][cy]=0;
        } else { // wall
            if(power) {
                vis[cx-1][cy]=1;
                esc(cx-1, cy, w+1, 0);
                vis[cx-1][cy]=0;
            }
        }
    }

    if(cx+1<=n && vis[cx+1][cy]==0) {
        if(miro[cx+1][cy]==0) {
            vis[cx+1][cy]=1;
            esc(cx+1, cy, w+1, power);
            vis[cx+1][cy]=0;
        } else { // wall 
            if(power) {
                vis[cx+1][cy]=1;
                esc(cx+1, cy, w+1, 0);
                vis[cx+1][cy]=0;
            }
        }
    }

    if(cy-1 >=0 && vis[cx][cy-1]==0) {
        if(miro[cx][cy-1]==0) {
            vis[cx][cy-1]=1;
            esc(cx, cy-1, w+1, power);
            vis[cx][cy-1]=0;
        } else {
            if(power) {
                vis[cx][cy-1]=1;
                esc(cx, cy-1, w+1, 0);
                vis[cx][cy-1]=0;
            }
        }
    }

    if(cy+1 <= m && vis[cx][cy+1]==0) {
        if(miro[cx][cy+1]==0) {
            vis[cx][cy+1]=1;
            esc(cx, cy+1, w+1, power);
            vis[cx][cy+1]=0;
        } else {
            if(power) {
                vis[cx][cy+1]=1;
                esc(cx, cy+1, w+1, 0);
                vis[cx][cy+1]=0;
            }
        }
    }
}
*/


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    cin >> hx >> hy >> ex >> ey;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin >> miro[i][j];
        }
    }

    /*
    esc(hx, hy, 0, 1);

    if(min_walk==987654321) cout << -1 << '\n';
    else cout << min_walk << '\n';
    */

    queue<tuple<int, int, int, int>> qu;
    qu.push(make_tuple(hx, hy, 1, 0));
    vis1[hx][hy]=1;
    vis2[hx][hy]=1;

    int cx, cy, power, w;
    while(!qu.empty()) {
        tie(cx, cy, power, w) = qu.front(); 
        qu.pop();

        if(cx==ex && cy==ey) {
            cout << w << '\n';
            return 0;
        }

        if(cx-1 >= 1) {
            if(miro[cx-1][cy]==0) {
                if(power && vis1[cx-1][cy]==0) {
                    vis1[cx-1][cy]=1;
                    qu.push(make_tuple(cx-1, cy, power, w+1));
                }
                else if(!power && vis2[cx-1][cy]==0) {
                    vis2[cx-1][cy]=1;
                    qu.push(make_tuple(cx-1, cy, power, w+1));
                }
            } else {
                if(power && vis2[cx-1][cy]==0) {
                    vis2[cx-1][cy]=1;
                    qu.push(make_tuple(cx-1, cy, 0, w+1));
                }
            }
        }

        if(cx+1<=n) {
            if(miro[cx+1][cy]==0) {
                if(power && vis1[cx+1][cy]==0) {
                    vis1[cx+1][cy]=1;
                    qu.push(make_tuple(cx+1, cy, power, w+1));
                }
                else if(!power && vis2[cx+1][cy]==0) {
                    vis2[cx+1][cy]=1;
                    qu.push(make_tuple(cx+1, cy, power, w+1));
                }

            } else {
                if(power && vis2[cx+1][cy]==0) {
                    vis2[cx+1][cy]=1;
                    qu.push(make_tuple(cx+1, cy, 0, w+1));
                }
            }
        }

        if(cy-1 >=1) {
            if(miro[cx][cy-1]==0) {
                if(power && vis1[cx][cy-1]==0) {
                    vis1[cx][cy-1]=1;
                    qu.push(make_tuple(cx, cy-1, power, w+1));
                }
                else if(!power && vis2[cx][cy-1]==0) {
                    vis2[cx][cy-1]=1;
                    qu.push(make_tuple(cx, cy-1, power, w+1));
                }
            } else {
                if(power && vis2[cx][cy-1]==0) {
                    vis2[cx][cy-1]=1;
                    qu.push(make_tuple(cx, cy-1, 0, w+1));
                }
            }
        }

        if(cy+1 <= m) {
            if(miro[cx][cy+1]==0) {
                if(power && vis1[cx][cy+1]==0) {
                    vis1[cx][cy+1]=1;
                    qu.push(make_tuple(cx, cy+1, power, w+1));
                }
                else if(!power && vis2[cx][cy+1]==0) {
                    vis2[cx][cy+1]=1;
                    qu.push(make_tuple(cx, cy+1, power, w+1));
                }
            } else {
                if(power && vis2[cx][cy+1]==0) {
                    vis2[cx][cy+1]=1;
                    qu.push(make_tuple(cx, cy+1, 0, w+1));
                }
            }
        }
    }

    cout << -1 << '\n';
}

