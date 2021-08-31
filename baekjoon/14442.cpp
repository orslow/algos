// BFS apply
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

bool soo[1005][1005];

bool vis[1005][1005][15];

int bx[4]={0, -1, 0, 1};
int by[4]={1, 0, -1, 0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    cin.ignore();

    string tmp;
    for(int i=1; i<=n; i++) {
        getline(cin, tmp);
        for(int j=1; j<=m; j++) {
            soo[i][j]=tmp[j-1]-'0';
        }
    }

    queue <tuple<int, int, int, int>> qu;
    qu.push(make_tuple(1, 1, k, 0));
    vis[1][1][k]=1;

    /*
    for(int i=1; i<=k; i++) {
        vis[1][1][i]=1;
    }
    */

    int x, y, po, p;
    while(!qu.empty()) {
        tie(x, y, po, p)=qu.front(); qu.pop();

        // cout << x << ' ' << y << ' ' << p << '\n';

        if(x==n && y==m) {
            cout << p+1 << '\n';
            return 0;
        }

        for(int i=0; i<4; i++) {
            int cx=x+bx[i];
            int cy=y+by[i];

            if(cx<=0 || cx>n || cy<=0 || cy>m) continue;

            if(soo[cx][cy]==0 && vis[cx][cy][po]==0) {
                vis[cx][cy][po]=1;
                qu.push(make_tuple(cx, cy, po, p+1));
            }
            if(soo[cx][cy]!=0 && po>0 && vis[cx][cy][po-1]==0) {
                vis[cx][cy][po-1]=1;
                qu.push(make_tuple(cx, cy, po-1, p+1));
            }
        }
    }

    cout << -1 << '\n';

}

