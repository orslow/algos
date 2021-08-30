// minimum spanning tree
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

char school[1001];

vector<pair<int, int>> ways[1001];

bool vis[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, u, v, d;
    cin >> n >> m;

    for(int i=1; i<=n; i++) {
        cin >> school[i];
    }
    for(int i=0; i<m; i++) {
        cin >> u >> v >> d;
        ways[u].push_back({v, d});
        ways[v].push_back({u, d});
    }

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    for(auto v: ways[1]) {
        if(school[1]!=school[v.first]) pq.push(make_tuple(v.second, 1, v.first));
    }
    vis[1]=1;

    int cost, st, ed, ans=0, cnt=0;
    while(!pq.empty()) {
        if(cnt==n-1) break;
        tie(cost, st, ed) = pq.top(); pq.pop();
        // if(vis[st]==1 && vis[ed]==1) continue;
        if(vis[ed]==1) continue;

        // cout << st << ' ' << ed << ' ' << cost << '\n';

        vis[ed]=true;
        ans+=cost;
        cnt++;
        for(auto v: ways[ed]) {
            if(vis[v.first]==0 && school[ed]!=school[v.first]) pq.push(make_tuple(v.second, ed, v.first));
        }
    }

    if(cnt==n-1) cout << ans << '\n';
    else cout << -1 << '\n';

}

