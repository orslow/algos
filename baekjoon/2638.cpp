// bfs, simulation
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

int so1[103][103];
bool wb[103][103];
bool vis[103][103];

int mx[4]={1, 0, -1, 0};
int my[4]={0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> so1[i][j];
        }
    }

    bool dup=1;
    int x,y,cx,cy,ans=0;
    while(dup) {
        ans++;
        dup=0;
        // 0: 내부, 1: 외부
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(so1[i][j]==0 && wb[i][j]==0) {

                    for(int i=0; i<n; i++) {
                        for(int j=0; j<m; j++) {
                            vis[i][j]=0;
                        }
                    }

                    queue <tuple<int, int>> qu;
                    qu.push(make_tuple(i, j));
                    while(!qu.empty()) {
                        tie(x, y)=qu.front();qu.pop();

                        if(x==0 || y==0 || x==n-1 || y==m-1 || wb[x][y]==1) {
                            wb[i][j]=1;
                            break;
                        }

                        for(int k=0; k<4; k++) {
                            cx=x+mx[k]; cy=y+my[k];
                            if(so1[cx][cy]==1 || vis[cx][cy]==1) continue;
                            qu.push(make_tuple(cx, cy));
                            vis[cx][cy]=1;
                        }
                    }
                }
            }
        }

        /*
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                cout << so1[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
        */

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(so1[i][j]==1) {
                    dup=1;
                    int cnt=0;
                    for(int k=0; k<4; k++) {
                        cx=i+mx[k]; cy=j+my[k];
                        if(wb[cx][cy]==1) cnt++;
                    }
                    if(cnt>=2) so1[i][j]=0;
                }
            }
        }
    }
    cout << ans-1;
}
