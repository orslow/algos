// bfs with idea
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

int mx[4]={1, 0, -1, 0};
int my[4]={0, -1, 0, 1};

int so1[103][103];
bool vis[103][103];

vector <pair<int, int>> isl[5003]; 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >>  so1[i][j];
        }
    }

    int cnt=1;
    int x, y, cx, cy, s;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(vis[i][j]!=0) continue;

            if(so1[i][j]==1) {
                vis[i][j]=1;
                queue <pair<int, int>> qu;
                qu.push({i, j});
                isl[cnt].push_back({i, j});
                so1[i][j]=cnt;

                pair<int, int> tmp;
                while(!qu.empty()) {
                    tmp=qu.front();qu.pop();
                    x=tmp.first;y=tmp.second;
                    for(int k=0; k<4; k++) {
                        cx=x+mx[k]; cy=y+my[k];
                        if(cx<0 || cy<0 || cx>=n || cy>=n) continue;
                        if(so1[cx][cy]==1 && vis[cx][cy]==0) {
                            vis[cx][cy]=1;
                            so1[cx][cy]=cnt;
                            qu.push({cx, cy});
                            isl[cnt].push_back({cx, cy});
                        }
                    }
                }
                cnt++;
            }
        }
    }

    int ans=10005;
    for(int i=1; i<cnt; i++) {
        queue <tuple<int, int, int>> qu;

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                vis[i][j]=0;
            }
        }

        for(auto d: isl[i]) {
            qu.push(make_tuple(d.first, d.second, 0));
            vis[d.first][d.second]=1;
        }

        bool keep=1;
        while(!qu.empty() && keep) {
            tie(x, y, s)=qu.front();qu.pop();
            for(int k=0; k<4; k++) {
                cx=x+mx[k];cy=y+my[k];
                if(cx<0 || cy<0 || cx>=n || cy>=n) continue;
                if(so1[cx][cy]!=i && vis[cx][cy]==0) {
                    vis[cx][cy]=1;
                    if(so1[cx][cy]==0) {
                        qu.push(make_tuple(cx, cy, s+1));
                    } else {
                        if(ans>s+1) ans=s+1;
                        keep=0;
                        break;
                    }
                }
            }
        }
    }

    cout << ans-1;
}

