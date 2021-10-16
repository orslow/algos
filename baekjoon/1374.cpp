// data structure
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,a,b,c;
    cin >> n;

    vector <pair<int, int>> m;

    for(int i=0; i<n; i++) {
        cin >> c >> a >> b;
        m.push_back({a, 1});
        m.push_back({b, -1});
    }

    sort(m.begin(), m.end());

    int cnt=0, ans=0;
    for(auto v: m) {
        if(v.second==1) {
            cnt++;
            if(cnt>ans) {
                ans=cnt;
            }
        } else {
            cnt--;
        }
    }

    cout << ans;
}
