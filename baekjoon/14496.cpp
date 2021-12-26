// BFS
#include <bits/stdc++.h>

using namespace std;

vector <int> so1[1001];
bool vis[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a,b,n,m,c,d;
    cin >> a >> b >> n >> m;

    for(int i=0; i<m; i++) {
        cin >> c >> d;
        so1[c].push_back(d);
        so1[d].push_back(c);
    }

    int ans=-1;
    queue <pair<int, int>> qu;
    qu.push({a, 0});
    vis[a]=1;

    while(!qu.empty()) {
        int p=qu.front().first, s=qu.front().second; qu.pop();

        if(p==b) {
            ans=s;
            break;
        }

        for(int g: so1[p]) {
            if(vis[g]==0) {
                vis[g]=1;
                qu.push({g, s+1});
            }
        }

    }

    cout << ans;
    
}
