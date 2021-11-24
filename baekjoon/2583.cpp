// bfs
#include <bits/stdc++.h>

using namespace std;

int n,m,k;

int mx[4]={1, 0, -1, 0};
int my[4]={0, 1, 0, -1};

int so1[103][103];
bool vis[103][103];

vector <int> w;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    int x1,y1,x2,y2;
    for(int i=0; i<k; i++) {
        cin >> x1 >> y1 >> x2 >> y2;

        for(int j=x1; j<x2; j++) {
            for(int k=y1; k<y2; k++) {
                so1[k][j]=1;
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(so1[i][j]==0 && vis[i][j]==0) {

                queue <pair<int, int>> qu;
                qu.push({i, j});
                vis[i][j]=1;
                int cur=1;
                while(!qu.empty()) {
                    int x=qu.front().first, y=qu.front().second; qu.pop();

                    for(int k=0; k<4; k++) {
                        int cx=x+mx[k], cy=y+my[k];

                        if(cx<0 || cy<0 || cx>=n || cy>=m) continue;
                        if(vis[cx][cy]==1 || so1[cx][cy]!=0) continue;
                        cur++;
                        vis[cx][cy]=1;
                        qu.push({cx, cy});
                    }
                }
                w.push_back(cur);
            }
        }
    }
    sort(w.begin(), w.end());
    cout << w.size() << '\n';
    for(auto v: w) cout << v << ' ';
}
