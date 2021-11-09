// BFS recycle
#include <bits/stdc++.h>

using namespace std;

int vis[501][501];

int mx[8]={-1, -2, -2, -1, 1, 2, 2, 1};
int my[8]={-2, -1, 1, 2, -2, -1, 1, 2};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,x,y,a,b,cx,cy,cur;
    cin >> n >> m;

    cin >> x >> y;

    queue <tuple<int, int, int>> qu;
    qu.push(make_tuple(x, y, 0));
    vis[x][y]=1;
    while(!qu.empty()) {
        tie(cx, cy, cur)=qu.front(); qu.pop();

        for(int j=0; j<8; j++) {
            int ux=cx+mx[j], uy=cy+my[j];
            if(ux<1 || uy<1 || ux>n || uy>n) continue;
            if(vis[ux][uy]>0) continue;
            vis[ux][uy]=cur+1;
            qu.push(make_tuple(ux, uy, cur+1));
        }
    }

    for(int i=0; i<m; i++) {
        cin >> a >> b;
        cout << vis[a][b] << ' ';
    }
}
