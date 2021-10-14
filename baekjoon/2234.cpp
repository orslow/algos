// bfs
#include <bits/stdc++.h>

using namespace std;

int so1[53][53];
pair<int, int> ro[53][53];

int mx[4]={0, -1, 0, 1};
int my[4]={-1, 0, 1, 0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> m >> n;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> so1[i][j];
        }
    }

    int cnt=0,x,y,cx,cy;

    int big=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {

            if(ro[i][j].first==0) {
                cnt++;
                queue <pair<int, int>> qu;
                vector <pair<int, int>> v;
                qu.push({i, j});
                ro[i][j].first=cnt;

                while(!qu.empty()) {
                    x=qu.front().first;y=qu.front().second; qu.pop();
                    v.push_back({x, y});
                    int s=so1[x][y];

                    for(int k=0; k<4; k++) {
                        if(s%2==0) {
                            cx=x+mx[k]; cy=y+my[k];
                            if(cx<0 || cy<0 || cx>=n || cy>=m) continue;
                            if(ro[cx][cy].first==0) {
                                ro[cx][cy].first=cnt;
                                qu.push({cx, cy});
                            }
                        }
                        s/=2;
                    }
                }
                if(v.size()>big) big=v.size();
                for(auto w: v) {
                    ro[w.first][w.second].second=v.size();
                }
            }
        }
    }

    int maxi=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(i+1<n && ro[i][j].first!=ro[i+1][j].first) {
                if(ro[i][j].second+ro[i+1][j].second>maxi) maxi=ro[i][j].second+ro[i+1][j].second;
            }
            if(j+1<m && ro[i][j].first!=ro[i][j+1].first) {
                if(ro[i][j].second+ro[i][j+1].second>maxi) maxi=ro[i][j].second+ro[i][j+1].second;
            }
        }
    }
    cout << cnt << '\n' << big << '\n' << maxi;
}
