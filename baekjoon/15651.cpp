// backtracking
#include <bits/stdc++.h>

using namespace std;

int n,m;

void go(vector<int> c, int d) {
    if(c.size()==m) {
        for(auto v: c) cout << v << ' ';
        cout << '\n';
        return;
    }

    for(int i=d; i<=n; i++) {
        c.push_back(i);
        go(c, d);
        c.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    vector <int> g;

    go(g, 1);
}
