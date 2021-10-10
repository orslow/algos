// sort vs set
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,a;
    cin >> n;

    set <int> so1;
    for(int i=0; i<n; i++) {
        cin >> a;
        so1.insert(a);
    }

    cin >> m;
    for(int i=0; i<m; i++) {
        cin >> a;
        if(so1.find(a)==so1.end()) {
            cout << 0 << ' ';
        } else {
            cout << 1 << ' ';
        }
    }
}
