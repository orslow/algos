// basic binary search
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int so1[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, f;
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> so1[i];
    }

    sort(so1, so1+n);

    cin >> m;
    
    int s, e, mi;
    bool found;
    for(int i=0; i<m; i++) {
        cin >> f;

        s=0; e=n-1;

        found=0;
        while(s <= e) {
            // cout << s << ", " << e << '\n';
            mi=(s+e)/2;

            if (so1[mi] == f) {
                cout << 1 << '\n';
                found=1;
                break;
            }

            if (f < so1[mi]) {
                e = mi-1;
            } else {
                s = mi+1;
            }
        }

        if(!found) cout << 0 << '\n';
    }
}

