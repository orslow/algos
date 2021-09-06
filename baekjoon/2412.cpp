// not just bfs but with idea
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

vector <pair<int, int>> ho;

bool vis[50001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, t, x, y, step, cx, cy, st, ed, f, idx;
    cin >> n >> t;

    ho.push_back({0, 0});
    for(int i=0; i<n; i++) {
        cin >> x >> y;
        ho.push_back({x, y});
    }

    sort(ho.begin(), ho.end());

    queue <tuple<int, int, int, int>> qu;
    qu.push(make_tuple(0, 0, 0, 0));

    vis[0]=1;

    while(!qu.empty()) {
        tie(x, y, step, idx)=qu.front();qu.pop();

        // cout << x << ' ' << y << ' ' << step << '\n';

        if(y==t) {
            cout << step;
            return 0;
        }
        for(int i=idx+1; i<=n; i++) {
            cx=ho[i].first;cy=ho[i].second;
            if(abs(cx-x)<=2 && abs(cy-y)<=2 && vis[i]==0) {
                qu.push(make_tuple(cx, cy, step+1, i));
                vis[i]=1;
            }
            if(abs(cx-x)>2) break;
        }
        for(int i=idx-1; i>=0; i--) {
            cx=ho[i].first;cy=ho[i].second;
            if(abs(cx-x)<=2 && abs(cy-y)<=2 && vis[i]==0) {
                qu.push(make_tuple(cx, cy, step+1, i));
                vis[i]=1;
            }
            if(abs(cx-x)>2) break;
        }
        
    }

    cout << -1;
}

