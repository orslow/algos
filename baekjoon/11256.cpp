// sort
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int j,n;
        cin >> j >> n;

        vector <int> b;
        int r,c;
        for(int i=0; i<n; i++) {
            cin >> r >> c;
            b.push_back(r*c);
        }

        sort(b.begin(), b.end(), greater<>());

        int ans=0;
        for(int v: b){
            ans++;
            j-=v;
            if(j<=0) break;
        }

        cout << ans << '\n';
    }
}
