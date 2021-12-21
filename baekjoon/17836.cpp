// BFS with conditions
#include <bits/stdc++.h>

using namespace std;

int so1[101][101];
bool vis[101][101];

int mx[4]={1, 0, -1, 0};
int my[4]={0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,t;
    cin >> n >> m >> t;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin >> so1[i][j];
        }
    }

    queue <tuple<int, int, int>> qu;
    qu.push(make_tuple(1, 1, 0));
    vis[1][1]=1;

    int ans=10001;
    int x,y,c,g;
    while(!qu.empty()) {
        tie(x,y,c)=qu.front(); qu.pop();
        if(x==n && y==m) {
            if(ans>c) ans=c;
            continue;
        }
        if(so1[x][y]==2) {
            if(n-x+m-y+c<=t && ans>n-x+m-y+c) ans=n-x+m-y+c;
            continue;
        }

        if(c+1>t) continue;
        for(int i=0; i<4; i++) {
            int cx=x+mx[i], cy=y+my[i];
            if(cx<1 || cy<1 || cx>n || cy>m) continue;
            if(so1[cx][cy]==1 || vis[cx][cy]!=0) continue;
            vis[cx][cy]=1;
            qu.push(make_tuple(cx, cy, c+1));
        }
    }

    if(ans==10001) cout << "Fail";
    else cout << ans;
}
