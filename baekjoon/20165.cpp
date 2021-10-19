// simulation well
#include <bits/stdc++.h>

using namespace std;

int so1[103][103];
char so2[103][103];

int n,m,r,ans;

void fe(int x, int y) {

    so2[x][y]='F';
    ans++;

    for(int i=y+1; i<y+so1[x][y]; i++) {
        if(i>m) break;
        if(so2[x][i]=='S') {
            fe(x, i);
        }
    }
}

void fw(int x, int y) {

    so2[x][y]='F';
    ans++;

    for(int i=y-1; i>y-so1[x][y]; i--) {
        if(i<1) break;
        if(so2[x][i]=='S') {
            fw(x, i);
        }
    }
}

void fs(int x, int y) {

    so2[x][y]='F';
    ans++;

    for(int i=x+1; i<x+so1[x][y]; i++) {
        if(i>n) break;
        if(so2[i][y]=='S') {
            fs(i, y);
        }
    }
}

void fn(int x, int y) {

    so2[x][y]='F';
    ans++;

    for(int i=x-1; i>x-so1[x][y]; i--) {
        if(i<1) break;
        if(so2[i][y]=='S') {
            fn(i, y);
        }
    }
}





int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> r;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin >> so1[i][j];
            so2[i][j]='S';
        }
    }

    int x,y;
    char d;
    for(int i=0; i<r; i++) {
        cin >> x >> y >> d;

        if(so2[x][y]=='F') continue;

        if(d=='E') {
            fe(x, y);
        } else if(d=='W') {
            fw(x, y);
        } else if(d=='S') {
            fs(x, y);
        } else {
            fn(x, y);
        }

        cin >> x >> y;
        so2[x][y]='S';
    }

    cout << ans << '\n';
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cout << so2[i][j] << ' ';
        }
        cout << '\n';
    }

}
