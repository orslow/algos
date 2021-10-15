// not hard but suffered
#include <bits/stdc++.h>

using namespace std;

int n,m;

int so1[5][5];

int vis[5][5];

int ans;

void go(int x, int y, int t) {

    if(x==n-1) {
        if(t>ans) ans=t;
        return;
    }

    if(!vis[x][y] && !vis[x][y+1] && !vis[x+1][y+1]) {

        vis[x][y]=1; vis[x][y+1]=1; vis[x+1][y+1]=1;

        if(y==m-2) {
            go(x+1, 0, t+so1[x][y]+so1[x][y+1]*2+so1[x+1][y+1]);
        } else {
            go(x, y+1, t+so1[x][y]+so1[x][y+1]*2+so1[x+1][y+1]);
        }

        vis[x][y]=0; vis[x][y+1]=0; vis[x+1][y+1]=0;
    }

    if(!vis[x][y+1] && !vis[x+1][y+1] && !vis[x+1][y]) {
        vis[x][y+1]=1; vis[x+1][y+1]=1; vis[x+1][y]=1;

        if(y==m-2) {
            go(x+1, 0, t+so1[x][y+1]+so1[x+1][y+1]*2+so1[x+1][y]);
        } else {
            go(x, y+1, t+so1[x][y+1]+so1[x+1][y+1]*2+so1[x+1][y]);
        }

        vis[x][y+1]=0; vis[x+1][y+1]=0; vis[x+1][y]=0;
    }

    if(!vis[x][y] && !vis[x+1][y] && !vis[x+1][y+1]) {
        vis[x][y]=1; vis[x+1][y]=1; vis[x+1][y+1]=1;

        if(y==m-2) {
            go(x+1, 0, t+so1[x][y]+so1[x+1][y]*2+so1[x+1][y+1]);
        } else {
            go(x, y+1, t+so1[x][y]+so1[x+1][y]*2+so1[x+1][y+1]);
        }

        vis[x][y]=0; vis[x+1][y]=0; vis[x+1][y+1]=0;
    }

    if(!vis[x][y] && !vis[x][y+1] && !vis[x+1][y]) {
        vis[x][y]=1; vis[x][y+1]=1; vis[x+1][y]=1;

        if(y==m-2) {
            go(x+1, 0, t+so1[x][y]*2+so1[x][y+1]+so1[x+1][y]);
        } else {
            go(x, y+1, t+so1[x][y]*2+so1[x][y+1]+so1[x+1][y]);
        }

        vis[x][y]=0; vis[x][y+1]=0; vis[x+1][y]=0;
    }

    if(y==m-2) {
        go(x+1, 0, t);
    } else {
        go(x, y+1, t);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> so1[i][j];
        }
    }

    go(0, 0, 0);

    cout << ans;
}
