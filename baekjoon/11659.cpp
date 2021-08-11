// sort of dp? (prefix sum)
#include <bits/stdc++.h>

using namespace std;

int ps[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, tmp;
    cin >> n >> m;

    ps[0] = 0;

    for(int i=1; i<=n; i++) {
        cin >> tmp;
        ps[i] = ps[i-1] + tmp;
    }

    int s, e;
    for(int i=0; i<m; i++) {
        cin >> s >> e;

        cout << ps[e] - ps[s-1] << '\n';
    }
}

