// solved with help -> hard to get recursion idea
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

int so1[503][503];
int vis[503][503];
int n,ans;

int mx[4]={0, 1, 0, -1};
int my[4]={1, 0, -1, 0};

int move(int x, int y) {
    if(vis[x][y]!=0) return vis[x][y];
    vis[x][y]=1;

    for(int i=0; i<4; i++) {
        int cx=x+mx[i], cy=y+my[i];
        if(cx<0 || cy<0 || cx>=n || cy>=n) continue;
        if(so1[x][y]<so1[cx][cy]) {
            vis[x][y]=max(move(cx, cy)+1, vis[x][y]);
        }
    }
    return vis[x][y];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >>  so1[i][j];
        }
    }

    int maxi=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            ans=max(move(i, j), ans);
        }
    }
    cout << ans;
}
