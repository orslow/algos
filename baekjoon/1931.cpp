// meeting room (basic greedy)
#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b) {
    if(a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, s, e;
    cin >> n;

    vector<pair<int, int> > mt;
    for(int i=0; i<n; i++) {
        cin >> s >> e;

        mt.push_back({s, e});
    }

    sort(mt.begin(), mt.end(), cmp);

    // for(auto v: mt) cout << v.first << ' ' << v.second << '\n';

    int ed=0, ans=0;
    for(auto v: mt) {
        if (v.first >= ed) {
            ans++;
            ed = v.second;
        }
    }

    cout << ans << '\n';
}


