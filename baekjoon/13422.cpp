// practice
#include <bits/stdc++.h>

using namespace std;

int so1[100005];

int main() {

    int t,n,m,k;
    cin >> t;

    while(t--) {
        cin >> n >> m >> k;

        for(int i=0; i<n; i++) {
            cin >> so1[i];
        }

        int l=0, r=m, cur=0;
        for(int i=0; i<r; i++) {
            cur+=so1[i];
        }

        int ans=0;
        if(n==m) {
            if(cur<k) ans++;
            cout << ans << '\n';
            continue;
        }

        while(l<n) {
            if(cur<k) ans++;
            cur-=so1[l]; cur+=so1[r];
            l++;
            r=(r+1)%n;
        }

        cout << ans << '\n';
    }
}

