// graph
#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> so1[10003];
int vis[10003];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,a,b,c,s,e,v,w,t,nes;
    cin >> n >> m;

    for(int i=0; i<m; i++) {
        cin >> a >> b >> c;
        so1[a].push_back({c, b});
        so1[b].push_back({c, a});
    }

    cin >> s >> e;

    priority_queue<pair<int, int>> pq;
    pq.push({1000000001, s});
    vis[s]=1000000001;

    int ans=0;
    while(!pq.empty()) {
        c=pq.top().first; v=pq.top().second; pq.pop();

        if(vis[v]>c) continue;

        for(auto u: so1[v]) {
            w=u.first; t=u.second;
            nes=min(c,w);
            if(vis[t]>=nes) continue;
            pq.push({nes, t});
            vis[t]=nes;
        }
    }

    cout << vis[e];
}
