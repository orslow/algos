// bfs, simulation
#include <bits/stdc++.h>

using namespace std;

int vis[103];
int so1[103];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;

    int a,b;
    for(int i=0; i<n; i++) {
        cin >> a >> b;
        so1[a]=b;
    }

    for(int i=0; i<m; i++) {
        cin >> a >> b;
        so1[a]=b;
    }

    queue <pair<int, int>> qu;
    qu.push({1, 0});
    vis[1]=1;

    while(!qu.empty()) {
        int cur=qu.front().first, step=qu.front().second; qu.pop();

        if(cur==100) {
            cout << step;
            return 0;
        }

        for(int i=1; i<=6; i++) {
            if(so1[cur+i]!=0) {
                if(vis[cur+i]==0 && vis[so1[cur+i]]==0) {
                    qu.push({so1[cur+i], step+1});
                    vis[cur+i]=1;
                    vis[so1[cur+i]]=1;
                }
            } else if(vis[cur+i]==0) {
                qu.push({cur+i, step+1});
                vis[cur+i]=1;
            }
        }
    }
}
