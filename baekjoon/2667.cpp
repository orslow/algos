#include <bits/stdc++.h>

using namespace std;

char so1[30][30];
bool vis[30][30];

int mx[4]={1, 0, -1, 0};
int my[4]={0, 1, 0, -1};

vector <int> t;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string s;
    for(int i=0; i<n; i++) {
        cin >> s;
        for(int j=0; j<n; j++) {
            so1[i][j]=s[j];
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(so1[i][j]=='1' && vis[i][j]==0) {
                queue <pair<int, int>> qu;
                qu.push({i, j});
                vis[i][j]=1;

                int cur=1;
                while(!qu.empty()) {
                    int x=qu.front().first, y=qu.front().second; qu.pop();

                    for(int k=0; k<4; k++) {
                        int cx=x+mx[k], cy=y+my[k];

                        if(cx<0 || cy<0 || cx>=n || cy>=n) continue;
                        if(vis[cx][cy]==1 || so1[cx][cy]!='1') continue;
                        cur++;
                        vis[cx][cy]=1;
                        qu.push({cx, cy});
                    }
                }
                t.push_back(cur);
            }
        }
    }
    cout << t.size() << '\n';
    sort(t.begin(), t.end());
    for(int c: t) {
        cout << c << '\n';
    }
}

