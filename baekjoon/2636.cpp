// basic bfs but suffer hardship
#include <bits/stdc++.h>

using namespace std;

int n,m;

int so1[103][103];
bool vis[103][103];

int xs[4] = {0, -1, 0, 1};
int ys[4] = {1, 0, -1, 0};

void check_hole(int x, int y) {

    queue <tuple<int, int>> qu;
    vector <tuple<int, int>> ve;

    qu.push(make_tuple(x, y));
    ve.push_back(make_tuple(x, y));

    vis[x][y]=1;

    int a,b;
    bool hole=1;
    while(!qu.empty()) {
        tie(a, b) = qu.front(); qu.pop();
        for(int i=0; i<4; i++) {
            int xa=a+xs[i];
            int ya=b+ys[i];

            if(xa<0 || xa>=n || ya<0 || ya>=m) continue;

            if(xa==0 || ya==0 || xa==n-1 || ya==m-1) {
                hole=0;
            }

            if(so1[xa][ya]==0 && vis[xa][ya]==0) {
                qu.push(make_tuple(xa, ya));
                ve.push_back(make_tuple(xa, ya));
                vis[xa][ya]=1;
            }

        }
    }

    if(hole) {
        for(auto v: ve) {
            tie(a, b) = v;
            so1[a][b]=2;
        }
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

    int turn=0;
    int ans;
    while(true) {

        for(int i=1; i<n-1; i++) {
            for(int j=1; j<m-1; j++) {
                if(so1[i][j]==0 && vis[i][j]==0) {
                    check_hole(i, j);
                }
            }
        }

        for(int i=1; i<n-1; i++) {
            for(int j=1; j<m-1; j++) {
                if(so1[i][j]==1) {
                    for(int k=0; k<4; k++) {
                        int sx=i+xs[k];
                        int sy=j+ys[k];
                        if(so1[sx][sy]==0) {
                            so1[i][j]=3;
                        }
                    }
                }
            }
        }

        ans=0;
        bool ct=0;
        for(int i=1; i<n-1; i++) {
            for(int j=1; j<m-1; j++) {
                if(so1[i][j]==3) {
                    ans++;
                    so1[i][j]=0;
                } else if(so1[i][j]==2) {
                    so1[i][j]=0;
                } else if(so1[i][j]==1) {
                    ct=1;
                }
                vis[i][j]=0;
            }
        }

        if(ct==0) {
            break;
        }
        turn++;
    }

    cout << turn+1 << '\n' << ans;
}
