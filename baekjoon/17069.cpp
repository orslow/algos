// not bfs but dp
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

ll vis[35][35][4];
int hs[35][35];
int n;

void dus(int x, int y, int d) {
    if(d==1) {
        if(y+2<=n && hs[x][y+2]==0) {
            vis[x][y+1][1]+=vis[x][y][1];
        }
        if(y+2<=n && x+1<=n && hs[x][y+2]==0 && hs[x+1][y+1]==0 && hs[x+1][y+2]==0) {
            vis[x][y+1][3]+=vis[x][y][1];
        }
    } else if(d==2) {
        if(x+2<=n && hs[x+2][y]==0) {
            vis[x+1][y][2]+=vis[x][y][2];
        }
        if(x+2<=n && y+1<=n && hs[x+1][y+1]==0 && hs[x+2][y]==0 && hs[x+2][y+1]==0) {
            vis[x+1][y][3]+=vis[x][y][2];
        }
    } else {
        if(y+2<=n && hs[x+1][y+2]==0) {
            vis[x+1][y+1][1]+=vis[x][y][3];
        }
        if(x+2<=n && hs[x+2][y+1]==0) {
            vis[x+1][y+1][2]+=vis[x][y][3];
        }
        if(x+2<=n && y+2<=n && hs[x+1][y+2]==0 && hs[x+2][y+1]==0 && hs[x+2][y+2]==0) {
            vis[x+1][y+1][3]+=vis[x][y][3];
        }
    }
}

void movi() {
    vis[1][1][1]=1;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            for(int k=1; k<=3; k++) {
                dus(i, j, k);
            }
        }
    }

    /*
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cout << vis[i][j][3] << ' ';
        }
        cout << '\n';
    }
    */
}

/*
void move() {

    queue <tuple<int, int, int>> qu;
    qu.push(make_tuple(1, 1, 1));

    int x,y,d;
    while(!qu.empty()) {
        tie(x, y, d)=qu.front();qu.pop();

        // cout << x << ' ' << y << ' ' << d << '\n';

        if(d==1 && x==n && y+1==n) {
            ans++;
            continue;
        } else if(d==2 && y==n && x+1==n) {
            ans++;
            continue;
        } else if(d==3 && x==n-1 && y==n-1) {
            ans++;
            continue;
        }

        if(d==1) { // 가로

            if(y+2<=n && hs[x][y+2]==0 && vis[x][y+1][1]==0) {
                // vis[x][y+1][1]=1;
                qu.push(make_tuple(x, y+1, 1));
            }
            if(y+2<=n && x+1<=n && hs[x][y+2]==0 && hs[x+1][y+1]==0 && hs[x+1][y+2]==0 && vis[x][y+1][3]==0) {
                // vis[x][y+1][3]=1;
                qu.push(make_tuple(x, y+1, 3));
            }

        } else if(d==2) { // 세로

            if(x+2<=n && hs[x+2][y]==0 && vis[x+1][y][2]==0) {
                // vis[x+1][y][2]=1;
                qu.push(make_tuple(x+1, y, 2));
            }
            if(x+2<=n && y+1<=n && hs[x+1][y+1]==0 && hs[x+2][y]==0 && hs[x+2][y+1]==0 && vis[x+1][y][3]==0) {
                // vis[x+1][y][3]=1;
                qu.push(make_tuple(x+1, y, 3));
            }

        } else { // 대각선

            if(y+2<=n && hs[x+1][y+2]==0 && vis[x+1][y+1][1]==0) {
                // vis[x+1][y+1][1]=1;
                qu.push(make_tuple(x+1, y+1, 1));
            }
            if(x+2<=n && hs[x+2][y+1]==0 && vis[x+1][y+1][2]==0) {
                // vis[x+1][y+1][2]=1;
                qu.push(make_tuple(x+1, y+1, 2));
            }
            if(x+2<=n && y+2<=n && hs[x+1][y+2]==0 && hs[x+2][y+1]==0 && hs[x+2][y+2]==0 && vis[x+1][y+1][3]==0) {
                // vis[x+1][y+1][3]=1;
                qu.push(make_tuple(x+1, y+1, 3));
            }

        }
    }
}
*/

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> hs[i][j];
        }
    }

    // 가로:1, 세로:2, 대각선:3
    movi();

    ll ans=vis[n][n-1][1]+vis[n-1][n][2]+vis[n-1][n-1][3];

    cout << ans;
}

