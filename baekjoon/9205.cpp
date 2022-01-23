// bfs
#include <bits/stdc++.h>

using namespace std;

bool vis[101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t,n,sx,sy,px,py;

    cin >> t;
    
    while(t--) {
        cin >> n;

        cin >> sx >> sy;

        int x,y;
        vector <pair<int, int>> sh;
        for(int i=0; i<n; i++) {
            cin >> x >> y;
            sh.push_back({x, y});
        }

        cin >> px >> py;

        for(int i=0; i<n; i++) vis[i]=0;

        bool r=0;
        queue <pair<int, int>> qu;
        qu.push({sx, sy});
        while(!qu.empty()) {
            int cx=qu.front().first, cy=qu.front().second; qu.pop();
            if(abs(px-cx)+abs(py-cy)<=1000) {
                r=1;
                break;
            }
            for(int i=0; i<n; i++) {
                if(vis[i]==0 && abs(sh[i].first-cx)+abs(sh[i].second-cy)<=1000) {
                    vis[i]=1;
                    qu.push({sh[i].first, sh[i].second});
                }
            }
        }

        if(r) cout << "happy" << '\n';
        else cout << "sad" << '\n';
    }
}
