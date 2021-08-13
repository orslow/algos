// math problem(LCM)
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, m, n, x, y, yu;

    cin >> t;


    bool sur;
    while(t--) {

        cin >> m >> n >> x >> y;

        if (y == n) 
            yu = 0;
        else
            yu = y;

        sur=0;
        for(int i=x; i<=m*n; i+=m) {
            if (i % n == yu) {
                cout << i << '\n';
                sur=1;
                break;
            }
        }

        if (sur == 0) cout << -1 << '\n';
    }
}

