// prim algorithm
#include <bits/stdc++.h>

using namespace std;

bool vis[1004];
vector <pair<int, int>> ways[1004];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,a,b,c,d;
    cin >> n >> m;

    for(int i=0; i<m; i++) {
        cin >> a >> b >> c;
        ways[a].push_back({b, c});
        ways[b].push_back({a, c});
    }

    priority_queue <tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

    for(auto t: ways[1])
        pq.push(make_tuple(t.second, 1, t.first));
    vis[1]=1;

    int ans=0,cnt=0;
    while(1) {
        tie(d, a, b)=pq.top();pq.pop();

        if(vis[b]==1) continue;
        vis[b]=1;
        ans+=d;
        cnt++;
        if(cnt==n-1) break;

        for(auto t: ways[b]) {
            if(!vis[t.first]) {
                pq.push(make_tuple(t.second, b, t.first));
            }
        }
    }

    cout << ans;
}
