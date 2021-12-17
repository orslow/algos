#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t,n,a;
    cin >> t;

    while(t--) {
        cin >> n;

        int mi=1000000, ma=-1000000;
        for(int i=0; i<n; i++) {
            cin >> a;
            if(a<mi) mi=a;
            if(a>ma) ma=a;
        }
        cout << mi << ' ' << ma << '\n';
    }
}
