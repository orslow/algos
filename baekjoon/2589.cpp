// bfs with some idea
#include <bits/stdc++.h>

using namespace std;

char so1[53][53];
bool vis[53][53];
bool done[53][53];

int mx[4]={1,0,-1,0};
int my[4]={0,1,0,-1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,x,y,c;
    cin >> n >> m;

    string t;
    for(int i=0; i<n; i++) {
        cin >> t;
        for(int j=0; j<m; j++) {
            so1[i][j]=t[j];
        }
    }

    int ans=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(so1[i][j]=='L' && done[i][j]==0) {
                done[i][j]=1;
                for(int i=0; i<n; i++) {
                    for(int j=0; j<m; j++) {
                        vis[i][j]=0;
                    }
                }

                queue <tuple<int, int, int>> qu;
                qu.push(make_tuple(i, j, 0));
                vis[i][j]=1;

                while(!qu.empty()) {
                    tie(x, y, c)=qu.front(); qu.pop();

                    if(c>ans) ans=c;

                    for(int k=0; k<4; k++) {
                        int cx=x+mx[k], cy=y+my[k];
                        if(cx<0 || cy<0 || cx>=n || cy>=m) continue;
                        if(vis[cx][cy]>0 || so1[cx][cy]=='W') continue;
                        vis[cx][cy]=1;
                        qu.push(make_tuple(cx, cy, c+1));
                    }
                }
            }
        }
    }

    /*
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout << vis[i][j] << ' ';
        }
        cout << '\n';
    }
    */

    cout << ans;
}
