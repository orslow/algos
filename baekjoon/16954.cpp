// passed but dirty.
#include <bits/stdc++.h>

using namespace std;

char so1[8][8];

bool vis[8][8][100];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            cin >> so1[i][j];
        }
    }


    queue <tuple<int, int, int> > qu;
    tuple<int, int, int> cur;
    int x, y, cup, curs=0;
    qu.push({7, 0, 0});
    while(!qu.empty()) {
        tie(x, y, cup) = qu.front();qu.pop();
        // x=cur.first; y=cur.second;

        if(curs != cup) {
            for(int i=7; i>=1; i--) {
                for(int j=0; j<8; j++) {
                    so1[i][j] = so1[i-1][j];
                }
            }
            for(int i=0; i<8; i++) {
                so1[0][i]='.';
            }

            curs+=1;
        }

        // cout << x << ' ' << y << ' ' << cup << '\n';
        if(x==0 && y==7) {
            cout << 1 << '\n';
            return 0;
        }

        // 12 (x-1)
        if(x-1>=0 && so1[x-1][y]!='#') {
            if(x-1 == 0 && y==7) {
                cout << 1 << '\n'; return 0;
            }
            if(x-2>=0) {
                if(so1[x-2][y]!='#' && vis[x-1][y][cup+1]==0) {
                    vis[x-1][y][cup+1]=1;
                    qu.push(make_tuple(x-1, y, cup+1));
                }
            }
            else {
                if(vis[x-1][y][cup+1]==0) {
                    vis[x-1][y][cup+1]=1;
                    qu.push(make_tuple(x-1, y, cup+1));
                }
            }
        }

        // 1:30 (x-1, y+1)
        if(x-1>=0 && y+1<8 && so1[x-1][y+1]!='#') {
            if(x-1 == 0 && y+1==7) {
                cout << 1 << '\n'; return 0;
            }
            if(x-2>=0) {
                if(so1[x-2][y+1]!='#' && vis[x-1][y+1][cup+1]==0) {
                    vis[x-1][y+1][cup+1]=1;
                    qu.push(make_tuple(x-1, y+1, cup+1));
                }
            }
            else {
                if(vis[x-1][y+1][cup+1]==0) {
                    vis[x-1][y+1][cup+1]=1;
                    qu.push(make_tuple(x-1, y+1, cup+1));
                }
            }
        }

        // 3 (y+1)
        if(y+1<8 && so1[x][y+1]!='#') {
            if(x == 0 && y+1==7) {
                cout << 1 << '\n'; return 0;
            }
            if(x-1>=0) {
                if(so1[x-1][y+1]!='#' && vis[x][y+1][cup+1]==0) {
                    vis[x][y+1][cup+1]=1;
                    qu.push(make_tuple(x, y+1, cup+1));
                }
            }
            else {
                if(vis[x][y+1][cup+1]==0) {
                    vis[x][y+1][cup+1]=1;
                    qu.push(make_tuple(x, y+1, cup+1));
                }
            }
        }

        // 4:30 (x+1, y+1)
        if(x+1<8 && y+1<8 && so1[x+1][y+1]!='#') {
            if(so1[x][y+1]!='#' && vis[x+1][y+1][cup+1]==0) {
                vis[x+1][y+1][cup+1]=1;
                qu.push(make_tuple(x+1, y+1, cup+1));
            }
        }

        // 6 (x+1)
        if(x+1<8 && so1[x+1][y]!='#' && vis[x+1][y][cup+1]==0) {
            vis[x+1][y][cup+1]=1;
            qu.push(make_tuple(x+1, y, cup+1));
        }

        // 7:30 (x+1, y-1)
        if(x+1<8 && y-1>=0 && so1[x+1][y-1]!='#') {
            if(so1[x][y-1]!='#' && vis[x+1][y-1][cup+1]==0) {
                vis[x+1][y-1][cup+1]=1;
                qu.push(make_tuple(x+1, y-1, cup+1));
            }
        }

        // 9 (y-1)
        if(y-1>=0 && so1[x][y-1]!='#') {
            if(x-1>=0) {
                if(so1[x-1][y-1]!='#' && vis[x][y-1][cup+1]==0) {
                    vis[x][y-1][cup+1]=1;
                    qu.push(make_tuple(x, y-1, cup+1));
                }
            }
            else {
                if(vis[x][y-1][cup+1]==0) {
                    vis[x][y-1][cup+1]=1;
                    qu.push(make_tuple(x, y-1, cup+1));
                }
            }
        }

        // 11:30 (x-1, y-1)
        if(x-1>=0 && y-1>=0 && so1[x-1][y-1]!='#') {
            if(x-2>=0) {
                if(so1[x-2][y-1]!='#' && vis[x-1][y-1][cup+1]==0) {
                    vis[x-1][y-1][cup+1]=1;
                    qu.push(make_tuple(x-1, y-1, cup+1));
                }
            }
            else {
                if(vis[x-1][y-1][cup+1]==0) {
                    qu.push(make_tuple(x-1, y-1, cup+1));
                }
            }
        }

        // stand (x, y)
        if(x-1>=0) {
            if(so1[x-1][y]!='#' && vis[x][y][cup+1]==0) {
                vis[x][y][cup+1]=1;
                qu.push(make_tuple(x, y, cup+1));
            }
        }
        else {
            if(vis[x][y][cup+1]==0) {
                vis[x][y][cup+1]=1;
                qu.push(make_tuple(x, y, cup+1));
            }
        }

    }

    cout << 0 << '\n';
}

