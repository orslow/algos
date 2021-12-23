// simulation(graph?)
#include <bits/stdc++.h>

using namespace std;

vector <int> so1[501];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;

    int a,b;
    for(int i=0; i<m; i++) {
        cin >> a >> b;
        so1[a].push_back(b);
        so1[b].push_back(a);
    }

    set <int> sa;
    for(int a: so1[1]) {
        sa.insert(a);
        for(int b: so1[a]) if(b!=1) sa.insert(b);
    }

    cout << sa.size();
}
