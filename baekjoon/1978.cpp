// divide until sqrt(su) (L29)
// divide only by odd number works
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, su;
    cin >> n;

    int ans=n;
    for(int i=0; i<n; i++) {
        cin >> su;

        if (su == 1) {
            ans--;
            continue;
        }
        if (su != 2 && su % 2 == 0) {
            ans--;
            continue;
        }

        for(int i=3; i*i <= su; i+=2) {
            if (su % i == 0) {
                ans--;
                break;
            }
        }
    }
    cout << ans << '\n';
}

