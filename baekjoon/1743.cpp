// basic bfs
#include <bits/stdc++.h>

using namespace std;

bool so1[101][101];
bool vis[101][101];

int mx[4]={1, 0, -1, 0};
int my[4]={0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,k;
    cin >> n >> m >> k;

    int a,b;
    for(int i=0; i<k; i++) {
      cin >> a >> b;
      so1[a-1][b-1]=1;
    }

    int ans=0;
    for(int i=0; i<n; i++) {
      for(int j=0; j<m; j++) {
        if(so1[i][j]==1 && vis[i][j]==0) {
          queue <pair<int, int>> qu;
          vis[i][j]=1;
          qu.push({i, j});
          int cnt=1;

          while(!qu.empty()) {
            int x=qu.front().first, y=qu.front().second; qu.pop();

            for(int k=0; k<4; k++) {
              int cx=x+mx[k], cy=y+my[k];

              if(cx<0 || cy<0 || cx>=n || cy>=m) continue;
              if(so1[cx][cy]!=1 || vis[cx][cy]==1) continue;
              vis[cx][cy]=1;
              qu.push({cx, cy});
              cnt++;
            }
          }
          if(cnt>ans)ans=cnt;
        }
      }
    }

    cout << ans;
}
