// dijkstra apply
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

int su[1000005];

bool rel[101][101];

int vis[101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    int a, b;
    while(k--) {
        cin >> a >> b;
        rel[a][b]=1;
        rel[b][a]=1;
    }

    bool small=true;
    for(int i=1; i<=n; i++) {
        if(!small) break;
        for(int j=1; j<=n; j++) {
            vis[j]=3000;
        }
        vis[i]=0;

        priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        pair<int, int> tmp;
        pq.push({0, i});
        while(!pq.empty()) {
            tmp=pq.top(); pq.pop();
            int ct=tmp.first, fr=tmp.second;

            if(vis[fr] != ct) continue;
            for(int j=1; j<=n; j++) {
                if(rel[fr][j]==1 && vis[j]>vis[fr]+1) {
                    vis[j]=vis[fr]+1;
                    pq.push({vis[j], j});
                }
            }
        }

        for(int i=1; i<=n; i++) {
            if(vis[i]>6) {
                small=false;
            }
        }
    }
    if(small) {
        cout << "Small World!" << '\n';
    } else {
        cout << "Big World!" << '\n';
    }
}
