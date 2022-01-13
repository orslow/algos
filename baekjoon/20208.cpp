// backtracking and care time complexity
#include <bits/stdc++.h>

using namespace std;

int so1[11][11];
bool vis[11];
vector <pair<int, int>> mil;

int mx[4]={1, 0, -1, 0};
int my[4]={0, 1, 0, -1};

int n,m,h,hx,hy,ans=0;

void go(int x, int y, int c, int r) { // c: milks, r: stamina

    // cout << x << ' ' << y << ' ' << c << ' ' << r << '\n';
    
    if(c>ans && abs(x-hx)+abs(y-hy)<=r) ans=c;

    for(int i=0; i<mil.size(); i++) {
        int dis=abs(x-mil[i].first)+abs(y-mil[i].second);
        if(dis<=r && vis[i]==0) {
            vis[i]=1;
            go(mil[i].first, mil[i].second, c+1, r-dis+h);
            vis[i]=0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> h;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> so1[i][j];
            if(so1[i][j]==1) {
                hx=i;
                hy=j;
            } else if(so1[i][j]==2) {
                mil.push_back({i, j});
            }
        }
    }

    go(hx, hy, 0, m);

    cout << ans;
}
