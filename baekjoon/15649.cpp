#include <bits/stdc++.h>

using namespace std;

int per[10];
bool vis[10];

int n, m;

void suy(int r) {

    if (r == m) {
        for(int i=0; i<m; i++) {
            cout << per[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i=1; i<=n; i++) {
        if(vis[i] == 0) { // not visited yet
            per[r] = i;
            vis[i] = 1;
            suy(r+1);
            vis[i] = 0;
        }
    }

}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    suy(0);
}

