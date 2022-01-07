// BFS, simulation
#include <bits/stdc++.h>

using namespace std;

char so1[13][7];
bool vis[13][7];

int mx[4]={1, 0, -1, 0};
int my[4]={0, 1, 0, -1};

void down() {
    for(int i=1; i<12; i++) {
        for(int j=0; j<6; j++) {
            if(so1[i][j]=='.') {
                for(int k=i; k>0; k--) {
                    so1[k][j]=so1[k-1][j];
                    so1[k-1][j]='.';
                }
            }
        }
    }
}

bool search(int i, int j, char c) {

    for(int i=0; i<12; i++) {
        for(int j=0; j<6; j++) {
            vis[i][j]=0;
        }
    }

    queue <pair<int, int>> qu;
    set <pair<int, int>> st;
    qu.push({i, j});
    st.insert({i, j});
    vis[i][j]=1;

    while(!qu.empty()) {
        int x=qu.front().first, y=qu.front().second; qu.pop();

        for(int i=0; i<4; i++) {
            int cx=x+mx[i], cy=y+my[i];
            if(cx<0 || cy<0 || cx>=12 || cy>=6) continue;
            if(vis[cx][cy]==1) continue;
            if(so1[cx][cy]==c) {
                vis[cx][cy]=1;
                qu.push({cx, cy});
                st.insert({cx, cy});
            }
        }
    }

    if(st.size()>=4) {
        for(auto p: st) {
            so1[p.first][p.second]='.';
        }
        return 1;
    }

    return 0;
}

bool pop() {
    bool re=0;
    for(int i=0; i<12; i++) {
        for(int j=0; j<6; j++) {
            vis[i][j]=0;
        }
    }
    for(int i=0; i<12; i++) {
        for(int j=0; j<6; j++) {
            if(so1[i][j]!='.' && vis[i][j]==0) {
                if(search(i, j, so1[i][j])) {
                    re=1;
                }
            }
        }
    }
    return re;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    for(int i=0; i<12; i++) {
        cin >> s;
        for(int j=0; j<6; j++) {
            so1[i][j]=s[j];
        }
    }

    int ans=0;
    while(1) {
        down();
        bool p=0;
        p=pop();
        down();
        if(!p) break;
        ans++;
    }

    cout << ans;
}
