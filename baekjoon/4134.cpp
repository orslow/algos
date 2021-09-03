// easy
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t, n;
    cin >> t;

    while(t--) {
        cin >> n;
        if(n==0 || n==1) {
            cout << 2 << '\n';
            continue;
        }
        bool con=1;
        while(1) {
            con=0;
            for(ll i=2; i*i<=n; i++) {
                if(n%i==0) {
                    con=1;
                    break;
                }
            }
            if(!con) {
                cout << n << '\n';
                break;
            }
            n++;
        }
    }

}
