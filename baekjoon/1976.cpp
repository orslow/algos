// graph
#include <bits/stdc++.h>

using namespace std;

bool so1[203][203];
bool vis[203];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> so1[i][j];
        }
    }

    int a;
    cin >> a;

    queue <int> qu;
    qu.push(a-1);

    set <int> t;
    while(!qu.empty()) {
        int c=qu.front(); qu.pop();

        t.insert(c);
        vis[c]=1;

        for(int i=0; i<n; i++) {
            if(so1[c][i] && !vis[i]) {
                qu.push(i);
            }
        }
    }

    int u;
    for(int i=0; i<m-1; i++) {
        cin >> u;
        if(t.find(u-1)==t.end()) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
}
