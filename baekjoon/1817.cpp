// easy simulation
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,a,cur;
    cin >> n >> m;
    
    cur=m;
    ll ans=0;
    for(int i=0; i<n; i++) {
        cin >> a;
        if(cur+a>m) {
            cur=a;
            ans++;
        } else {
            cur+=a;
        }
    }
    cout << ans;
}
