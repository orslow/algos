// Prim recap and apply
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

vector <pair<int, int> > bridge[100005];

int route[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, s, e;
    cin >> n >> m >> s >> e;

    int h1, h2, k;
    while(m--) {
        cin >> h1 >> h2 >> k;
        bridge[h1].push_back({h2, k});
        bridge[h2].push_back({h1, k});
    }

    priority_queue<tuple<int, int, int> > cands;
    for(auto b: bridge[s]) {
        h2=b.first; k=b.second;
        cands.push(make_tuple(k, s, h2));
    }
    route[s]=1000001; // end

    while(!cands.empty()) {
        tie(k, h1, h2)=cands.top(); cands.pop();

        if(route[h1]!=0 && route[h2]!=0) continue;

        route[h2]=min(route[h1], k);
        if(h2==e) break;

        for(auto b: bridge[h2]) {
            cands.push(make_tuple(b.second, h2, b.first));
        }
    }

    /*
    for(int i=1; i<=n; i++) {
        cout << route[i] << ' ';
    }
    cout << '\n';
    */

    cout << route[e] << '\n';

}

