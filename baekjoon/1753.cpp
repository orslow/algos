// basic dijkstra
#include <bits/stdc++.h>

using namespace std;

vector <pair<int, int> > so1[20001];

int dd[20001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, e, fr;
    cin >> n >> e;

    cin >> fr;

    int u, v, w;
    for(int i=0; i<e; i++) {
        cin >> u >> v >> w;
        so1[u].push_back({w, v});
    }

    for(int i=1; i<=n; i++) dd[i]=987654321;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > qu;
    qu.push({0, fr});
    dd[fr]=0;

    while(!qu.empty()) {
        auto cur = qu.top(); qu.pop();
        int dis=cur.first; int ver=cur.second;

        if(dd[ver] != dis) continue;

        for(int i=0; i<so1[ver].size(); i++) {
            auto sir = so1[ver][i];
            int cw=sir.first; int vt=sir.second;
            if(dis+cw < dd[vt]) {
                dd[vt] = dis+cw;
                qu.push({dis+cw, vt});
            }
        }
    }

    for(int i=1; i<=n; i++) {
        if(dd[i] != 987654321)
            cout << dd[i] << '\n';
        else
            cout << "INF" << '\n';
        
    }
}

