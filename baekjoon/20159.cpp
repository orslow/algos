// not easy partial sum
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,x;
    cin >> n;

    int c[100003], h1[100003], h2[100003];
    for(int i=1; i<=n; i++) {
        cin >> c[i];
        if(i%2==1) {
            h1[i]=h1[i-1]+c[i];
            h2[i]=h2[i-1];
        }
        else {
            h2[i]=h2[i-1]+c[i];
            h1[i]=h1[i-1];
        }
    }

    int ans=0;
    for(int i=1; i<=n; i++) {
        if(i%2==1) { // my turn
            ans = max(ans, h1[i-1]+h2[n-1]-h2[i]+c[n]);
        }
        else {
            ans = max(ans, h1[i-1]+h2[n-1]-h2[i-1]);
        }
        // cout << i << ' ' <<  ans << '\n';
    }
    cout << ans;
}
