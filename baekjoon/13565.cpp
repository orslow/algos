// basic bfs
#include <bits/stdc++.h>

using namespace std;

int so1[1004][1004];
bool vis[1004][1004];

int mx[4]={-1, 1, 0, 0};
int my[4]={0, 0, -1, 1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;

    string s;
    for(int i=0; i<n; i++) {
        cin >> s;
        for(int j=0; j<m; j++) {
            so1[i][j]=s[j]-48;
        }
    }

    queue <pair<int, int>> qu;

    for(int i=0; i<m; i++) {
        if(so1[0][i]==0) {
            qu.push({0, i});
        }
    }

    while(!qu.empty()) {
        int x=qu.front().first, y=qu.front().second; qu.pop();

        if(x==n-1) {
            cout << "YES";
            return 0;
        }

        for(int i=0; i<4; i++) {
            int cx=x+mx[i], cy=y+my[i];

            if(cx<0 || cy<0 || cx>=n || cy>=m) continue;
            if(so1[cx][cy]==1 || vis[cx][cy]==1) continue;
            vis[cx][cy]=1;
            qu.push({cx, cy});
        }
    }

    cout << "NO";
}
