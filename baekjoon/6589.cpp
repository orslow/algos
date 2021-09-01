// dijkstra?
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

map<string, vector<pair<string, int>>> ways;
map<string, int> vis;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, r, w, q=1;
    while(1) {
        cin >> n >> r;

        if(n==0 && r==0) break;

        string a, b;
        for(int i=0; i<r; i++) {
            cin >> a >> b >> w;
            ways[a].push_back({b, w});
            ways[b].push_back({a, w});
            vis[a]=987654323;
            vis[b]=987654323;
        }

        string st, ed;
        cin >> st >> ed;

        priority_queue<tuple<int, string, string>> pq;
        for(auto p: ways[st]) {
            pq.push(make_tuple(p.second, st, p.first));
        }
        tuple<int, string, string> tmp;
        string s, e;
        while(!pq.empty()) {
            tie(w, s, e)=pq.top();pq.pop();
            if(vis[e]!=987654323) continue;
            vis[e]=w;
            // cout << w << ' ' << s << ' ' << e << '\n';
            vis[e]=min(w, vis[s]);
            for(auto p: ways[e]) {
                pq.push(make_tuple(p.second, e, p.first));
            }
            if(e==ed) break;
        }

        cout << "Scenario #" << q++ << '\n';
        cout << vis[e] << ' ' << "tons" << "\n\n";
    }

}

